#include "OfflineServer.hpp"

#define BUFF_SIZE 128

using namespace placeholders;

//初始化配置等信息
OfflineServer::OfflineServer(string ip, int port)
{
    ip_ = ip;
    port_ = port;

    pool_ = Connect_pool::get_instance();
}

//开始服务
void OfflineServer::run()
{
    muduo::net::InetAddress address(ip_, port_);
    muduo::net::TcpServer server(&loop_, address, "OfflineServer");

    // 注册zookeeper节点
    ZKClient client;
    client.start();
    string server_path = "/OfflineService/server";
    char data[BUFF_SIZE] = {0};
    sprintf(data, "%s:%d", ip_.c_str(), port_);
    client.create(server_path, data, strlen(data), ZOO_EPHEMERAL);

    //绑定回调函数
    server.setMessageCallback(bind(&OfflineServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&OfflineServer::on_connect, this, _1));

    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

//读写事件回调函数
void OfflineServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    string recv = buffer->retrieveAllAsString();
    ik_OfflineServer::Request request;
    request.ParseFromString(recv);
    if (request.type() == "WriteOffline")
    {
        //反序列化
        ik_OfflineServer::WriteOfflineRequest write_request;
        write_request.ParseFromString(request.request_msg());
        int friend_id = write_request.friend_id();
        string msg = write_request.msg();
        //写入数据库
        write_offlineMsg(friend_id, msg);
    }
    else if (request.type() == "ReadOffline")
    {
        //反序列化
        ik_OfflineServer::WriteOfflineRequest write_request;
        write_request.ParseFromString(request.request_msg());
        int userid = write_request.friend_id();

        //执行业务
        vector<string> offline_msg = read_offlineMsg(userid);

        //序列化
        ik_OfflineServer::ReadOfflineResponse response;
        for (int i = 0; i < offline_msg.size(); i++)
        {
            response.add_msg(offline_msg[i]);
        }
        //信息发送
        string send = response.SerializeAsString();
        conn->send(send);
    }
}

//连接事件回调函数
void OfflineServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
    //断开连接
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

//写离线消息
bool OfflineServer::write_offlineMsg(int friend_id, string msg)
{
    //获取连接池连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into OfflineMessage values(%d,'%s')", friend_id, msg);
    return conn->update(sql);
}
//读离线消息
vector<string> OfflineServer::read_offlineMsg(int myid)
{
    //获取连接池连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select message from OfflineMessage where userid=%d", myid);
    MYSQL_RES *res = conn->query(sql);
    MYSQL_ROW row;

    vector<string> ret;
    while (row = mysql_fetch_row(res))
    {
        ret.push_back(row[0]);
    }

    mysql_free_result(res);

    //删除原来的离线消息
    memset(sql, 0, BUFF_SIZE);
    sprintf(sql, "delete from OfflineMessage where userid=%d", myid);
    conn->update(sql);
    return ret;
}
