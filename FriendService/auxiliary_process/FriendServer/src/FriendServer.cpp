#include "FriendServer.hpp"

#define BUFF_SIZE 128

using namespace placeholders;

FriendServer::FriendServer(string ip, int port)
{
    ip_ = ip;
    port_ = port;

    pool_ = Connect_pool::get_instance();
}

//服务器运行
void FriendServer::run()
{
    muduo::net::InetAddress address(ip_, port_);
    muduo::net::TcpServer server(&loop_, address, "FriendServer");

    // 注册zookeeper节点
    ZKClient client;
    client.start();
    string server_path = "/FriendService/server";
    char data[BUFF_SIZE] = {0};
    sprintf(data, "%s:%d", ip_.c_str(), port_);
    client.create(server_path, data, strlen(data));

    //绑定回调函数
    server.setMessageCallback(bind(&FriendServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&FriendServer::on_connect, this, _1));

    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

//读写事件回调函数
void FriendServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    string recv = buffer->retrieveAllAsString();
    ik_FriendServer::Request request;
    request.ParseFromString(recv);
    if (request.type() == "GetFriendList")
    {
        //反序列化
        ik_FriendServer::FriendListRequest friendList_request;
        friendList_request.ParseFromString(request.request());
        int userid = friendList_request.id();
        //获取好友列表信息
        vector<User> users = get_friendlist(userid);
        //组织返回消息
        ik_FriendServer::FriendListResponse response;
        for (int i = 0; i < users.size(); ++i)
        {
            ik_FriendServer::FriendInfo *info = response.add_friends();
            info->set_id(users[i].get_id());
            info->set_name(users[i].get_name());
        }

        string send = response.SerializeAsString();
        conn->send(send);
    }
}

//连接事件回调函数
void FriendServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
}

//获取userid 用户的好友列表
vector<User> FriendServer::get_friendlist(int userid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select User.id,User.name from Friend,User where Friend.userid=%d and User.id=Friend.friendid", userid);
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

//获得userid用户信息
User FriendServer::get_userinfo(int userid)
{
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select name from User where id=%d", userid);
    MYSQL_RES *res = conn->query(sql);
    User user;
    MYSQL_ROW row = mysql_fetch_row(res);
    user.set_id(userid);
    user.set_name(row[0]);

    mysql_free_result(res);
    return user;
}

//userid 的用户添加好友 friendid
void FriendServer::add_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into Friend values(%d,%d)", userid, friendid);

    conn->update(sql);
}

//删除userid用户的好友 friendid
void FriendServer::delete_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from Friend where userid=%d and friendid=%d", userid, friendid);

    conn->update(sql);
}