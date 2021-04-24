#include "UserServer.hpp"

using namespace placeholders;

#define BUFF_SIZE 128

UserServer::UserServer(string ip, int port) : stub_(new RpcChannel())
{
    ip_ = ip;
    port_ = port;
    pool_ = Connect_pool::get_instance();
    if (nullptr == pool_)
    {
        ik::LogRequest request;
        request.set_name("UserServer");
        request.set_msg("create mysql pool error");
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

void UserServer::run()
{
    //初始化网络层
    muduo::net::InetAddress address(ip_.c_str(), port_);
    muduo::net::TcpServer server(&loop_, address, "UserServer");

    server.setMessageCallback(bind(&UserServer::msg_callback, this, _1, _2, _3));
    server.setConnectionCallback(bind(&UserServer::conn_callback, this, _1));

    //注册zookeeper节点
    ZKClient zk_client;
    zk_client.start();
    string server_path = "/UserService/server";
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "%s:%d", ip_.c_str(), port_);
    if (zk_client.create(server_path, buffer, strlen(buffer), ZOO_EPHEMERAL) == false)
    {
        ik::LogRequest request;
        string name = "UserServer ";
        name += buffer;
        request.set_name(name);
        request.set_msg("zookeeper connect error!");
        google::protobuf::Empty response;
        stub_.Log_ERROR(nullptr, &request, &response, nullptr);
    }
    else
    {
        ik::LogRequest request;
        string name = "UserServer ";
        name += buffer;
        request.set_name(name);
        request.set_msg("zookeeper connect!");
        google::protobuf::Empty response;
        stub_.Log_ERROR(nullptr, &request, &response, nullptr);
    }
    //开启事件循环
    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

//连接事件回调函数
void UserServer::msg_callback(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化由UserService传过来的序列化数据
    string message = buffer->retrieveAllAsString();
    ik_UserServer::Request request;
    request.ParseFromString(message);

    //登录业务
    if (request.type() == "Login")
    {
        // 反序列化数据得到 id、password
        ik_UserServer::LoginRequest login_request;
        login_request.ParseFromString(request.request());
        int id = login_request.id();
        string password = login_request.password();

        //执行具体的Login方法，执行成功is_success被设置为true
        ik_UserServer::LoginReponse login_response;
        if (Login(id, password) == true)
        {
            login_response.set_is_success(true);
        }
        else
        {
            login_response.set_is_success(false);
            ik_UserServer::ErrorMsg *msg = login_response.mutable_msg();
            msg->set_message("login error");
        }
        //序列化结果 并将结果返回
        string send = login_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "Register")  //注册业务
    {
        ik_UserServer::RegisterRequest register_request;
        register_request.ParseFromString(request.request());
        string name = register_request.name();
        string password = register_request.password();
        //cout<<name<<" "<<password<<endl;
        ik_UserServer::RegisterResponse register_response;
        int id = Register(name, password);
        if (id < 0)
        {
            register_response.set_is_success(false);
        }
        else
        {
            register_response.set_is_success(true);
            register_response.set_id(id);
        }
        string send = register_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "LoginOut")  //注销业务
    {
        ik_UserServer::LoginOutRequest out_request;
        out_request.ParseFromString(request.request());
        int id = out_request.id();

        LoginOut(id);
    }
    else //其他业务，这里是没有，所以向LogServer服务器打印一条日志信息
    {
        ik::LogRequest request;
        request.set_name("UserServer");
        string message = "UserServer:";
        message += ip_.c_str();
        message += " not have this service!";
        request.set_msg(message);
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

//连接事件回调函数
void UserServer::conn_callback(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        //和rpc client断开连接
        conn->shutdown();
    }
}

//登录
bool UserServer::Login(int id, string password)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select * from User where id=%d and password='%s'", id, password.c_str());
    MYSQL_RES *res = conn->query(sql);
    if (res == nullptr)
    {
        mysql_free_result(res);
        return false;
    }
    else
    {
        //释放结果，否则会失败
        mysql_free_result(res);
        //更新用户状态为在线
        memset(sql, 0, BUFF_SIZE);
        sprintf(sql, "update User set state='online' where id=%d;", id);
        if (false == conn->update(sql))
        {
            ik::LogRequest request;
            request.set_name("UserServer");
            request.set_msg(sql, strlen(sql));
            google::protobuf::Empty response;
            stub_.Log_ERROR(nullptr, &request, &response, nullptr);
            return false;
        }
        return true;
    }
}

//注销
void UserServer::LoginOut(int id)
{
    //更新数据库User 状态为offline
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "update User set state='offline' where id=%d", id);
    conn->update(sql);
}

//注册 成功返回注册的账户，失败返回-1
int UserServer::Register(string name, string password)
{
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into User(name,password) values('%s','%s')", name.c_str(), password.c_str());
    //cout << sql << endl;
    if (false == conn->update(sql))
    {
        ik::LogRequest request;
        request.set_name("UserServer");
        request.set_msg(sql, strlen(sql));
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
        return false;
    }
    return mysql_insert_id(conn->get_connection());
}
