#include "LogSend.hpp"
#include "LogSend.pb.h"
#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
using namespace placeholders;

#define SEND_SIZE 256

//开始服务
void LogSend::run(string ip, int port)
{
    muduo::net::InetAddress address(ip, port);
    muduo::net::TcpServer server(&loop_, address, "LogSend");

    server.setMessageCallback(bind(&LogSend::send_file, this, _1, _2, _3));
    server.setConnectionCallback(bind(&LogSend::close_conn, this, _1));
    server.setThreadNum(2);

    server.start();
    loop_.loop();
}

// 读取文件并发送信息，绑定到muduo的on_message
void LogSend::send_file(const muduo::net::TcpConnectionPtr &conn,
                        muduo::net::Buffer *buf,
                        muduo::Timestamp stamp)
{
    string recv = buf->retrieveAllAsString().c_str();
    ik::LogSendRequest request;
    request.ParseFromString(recv);

    string file_path = "../log/";
    file_path += request.node_name();
    file_path += "/";
    file_path += request.time()+"_log.txt";
    cout << file_path << endl;

    ik::LogSendReponse response;
    int count = 1;
    char send_buf[SEND_SIZE] = {0};
    FILE *fp = fopen(file_path.c_str(), "r");
    while (!feof(fp))
    {
        memset(send_buf, 0, SEND_SIZE);
        fgets(send_buf, SEND_SIZE, fp);
        response.set_serial(count++);
        response.set_is_end(false);
        response.set_msg(send_buf);

        string send_str;
        response.SerializePartialToString(&send_str);
        conn->send(send_str.c_str(), send_str.size());
    }

    response.set_serial(count++);
    response.set_is_end(true);

    string send_str;
    response.SerializePartialToString(&send_str);
    conn->send(send_str.c_str(), send_str.size());
}

// 关闭连接
void LogSend::close_conn(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        //和rpc client断开连接
        conn->shutdown();
    }
}