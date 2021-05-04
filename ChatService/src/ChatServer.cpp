#include "ChatServer.hpp"

#include <iostream>
using namespace placeholders;

#define BUFF_SIZE 128

ChatServer::ChatServer(string redis_ip, int redis_port) : redis_client_(redis_ip, redis_port),
                                                          stub_(new RpcChannel),
                                                          offline_stub_(new RpcChannel)
{
}

//开启服务
void ChatServer::run(string ip, int port)
{
    //初始化服务器信息
    muduo::net::InetAddress address(ip, port);
    muduo::net::TcpServer server(&loop_, address, "ChatServer");

    // 设置回调函数
    server.setMessageCallback(bind(&ChatServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&ChatServer::on_connect, this, _1));
    server.setThreadNum(4);

    //连接redis服务器
    redis_client_.connect();

    //初始化zookeeper配置中心并注册节点
    zk_client_.start();
    string zk_path = "/ChatService/server";
    string zk_data = ip + ":" + to_string(port);
    zk_client_.create(zk_path, zk_path.c_str(), zk_path.size(), ZOO_EPHEMERAL);

    //开启muduo服务
    server.start();
    loop_.loop();
}

//连接事件回调函数
void ChatServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化
    string recv_str = buffer->retrieveAllAsString();
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_str);

    //得到用户登录的ip地址
    string host = redis_client_.get_host(request.id());
    //如果当前用户没登陆,写入离线消息
    if (host == "")
    {
        ik_OfflineService::WriteOfflineRequest write_request;
        write_request.set_friend_id(request.id());
        write_request.set_msg(request.msg());
        google::protobuf::Empty em;
        RpcControl controller;
        offline_stub_.WriteOffline(&controller, &write_request, &em, nullptr);
        return;
    }

    auto it = channel_map_.find(host);
    if (it == channel_map_.end()) //记录里面没有这个链接
    {
        int cliend_fd = establish_connection(host);
        channel_map_[host] = cliend_fd;
    }

    //序列化
    ik_Proxy::PoxryMessage poxry_request;
    poxry_request.set_type("ConveyMsg");
    poxry_request.set_request_msg(recv_str);

    string send_str = poxry_request.SerializeAsString();
    //转发此信息
    auto channel = channel_map_.find(host);
    int fd = channel->second;
    if (send(fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印错误日志
        ik::LogRequest log_request;
        log_request.set_name("ChatServer " + host);
        char error_buffer[BUFF_SIZE] = {0};
        sprintf(error_buffer, "send error ,errno:%d", errno);
        log_request.set_msg(error_buffer);
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }
}

//连接事件回调函数
void ChatServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
    //关闭连接
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

//根据host建立连接
int ChatServer::establish_connection(string host)
{
    //解析ip和port
    int index = host.find(":");
    string ip = host.substr(0, index);
    int port = atoi(host.substr(index + 1, host.size() - index).c_str());

    //创建socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        //打印错误日志
        ik::LogRequest request;
        request.set_name("ChatServer " + host);
        request.set_msg("create client fd error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &request, &em, nullptr);

        close(client_fd);
        return -1;
    }

    //配置服务器信息
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    //连接
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        //打印错误日志
        ik::LogRequest request;
        request.set_name("ChatServer " + host);
        request.set_msg("establish connect error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &request, &em, nullptr);

        close(client_fd);
        return -1;
    }
    return client_fd;
}