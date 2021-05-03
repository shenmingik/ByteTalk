#include "GroupServer.hpp"

#define BUFF_SIZE 128

using namespace placeholders;

//初始化server信息
GroupServer::GroupServer(string ip, int port)
{
    ip_ = ip;
    port_ = port;

    pool_ = Connect_pool::get_instance();
}

//开始运行服务
void GroupServer::run()
{
    //初始化服务器底层网络信息
    muduo::net::InetAddress address(ip_, port_);
    muduo::net::TcpServer server(&loop_, address, "GroupServer");

    //⚙工作线程数，连接事件回调函数，读写事件回调函数
    server.setThreadNum(4);
    server.setMessageCallback(bind(&GroupServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&GroupServer::on_connet, this, _1));

    zk_client_.start();
    string server_path = "/GroupService/server";
    string host = ip_ + ":" + to_string(port_);
    zk_client_.create(server_path, host.c_str(), host.size(), ZOO_EPHEMERAL);

    server.start();
    loop_.loop();
}

//绑定连接事件
void GroupServer::on_connet(const muduo::net::TcpConnectionPtr &conn)
{
    //简单断开连接
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

//绑定连接读写事件
void GroupServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化
    string recv_str = buffer->retrieveAllAsString();
    ik_ChatServer::Request request;
    request.ParseFromString(recv_str);

    //判断业务逻辑
    if (request.type() == "AddGroup")
    {
        ik_ChatServer::AddGroupRequest add_request;
        add_request.ParseFromString(request.request_msg());
        int userid = add_request.userid();
        int groupid = add_request.group_id();

        add_group(userid, groupid);
    }
    else if (request.type() == "QuitGroup")
    {
        ik_ChatServer::QuitGroupRequest quit_request;
        quit_request.ParseFromString(request.request_msg());
        int userid = quit_request.userid();
        int groupid = quit_request.groupid();

        quit_group(userid, groupid);
    }
    else if (request.type() == "CreateGroup")
    {
        ik_ChatServer::CreateGroupRequest create_request;
        create_request.ParseFromString(request.request_msg());
        int userid = create_request.userid();
        string group_name = create_request.group_name();

        int groupid = create_group(userid, group_name);
        if (groupid != -1)
        {
            add_group(userid, groupid);
            ik_ChatServer::CreateGroupResponse response;
            response.set_grouid(groupid);
            conn->send(response.SerializeAsString());
        }
    }
    else if (request.type() == "GetGroupUsers")
    {
        ik_ChatServer::GetGroupUsersRequest get_request;
        get_request.ParseFromString(request.request_msg());

        int groupid = get_request.group_id();
        vector<User> users = get_group_users(groupid);
        ik_ChatServer::GetGroupUsersResponse get_response;
        ik_ChatServer::UserInfo *user = nullptr;
        for (int i = 0; i < users.size(); i++)
        {
            user = get_response.add_users();
            user->set_id(users[i].get_id());
            user->set_name(users[i].get_name());
        }
        conn->send(get_response.SerializeAsString());
        return;
    }
}

//将userid所代表的用户添加到groupid的群里
bool GroupServer::add_group(int userid, int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into GroupUser values(%d,%d)", userid, groupid);
    return conn->update(sql);
}

//创建群，群名为group_name,返回群号
int GroupServer::create_group(int userid, string group_name)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织并执行sql语句
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into AllGroup(groupname) values('%s')", group_name.c_str());
    conn->update(sql);

    return mysql_insert_id(conn->get_connection());
}

//在groupid的群里删除userid这一列
bool GroupServer::quit_group(int userid, int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from GroupUser where userid=%d and groupid=%d", userid, groupid);
    return conn->update(sql);
}

//得到群组里所有用户的信息
vector<User> GroupServer::get_group_users(int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select User.id,User.name from User,GroupUser where GroupUser.groupid=%d and GroupUser.userid=User.id", groupid);
    MYSQL_RES *res = conn->query(sql);
    MYSQL_ROW row;

    vector<User> ret;
    while (row = mysql_fetch_row(res))
    {
        User user;
        user.set_id(atoi(row[0]));
        user.set_name(row[1]);
        ret.push_back(user);
    }

    mysql_free_result(res);
    return ret;
}