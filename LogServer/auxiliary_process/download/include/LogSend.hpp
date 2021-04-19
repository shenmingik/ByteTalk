#pragma once
#include "LogSend.pb.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>
#include <string>

using namespace std;

class LogSend
{
public:
    //开始服务
    void run(string ip, int port);

    // 读取文件并发送信息，绑定到muduo的on_message
    void send_file(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf, muduo::Timestamp stamp);

    // 关闭连接
    void close_conn(const muduo::net::TcpConnectionPtr &conn);

private:
    muduo::net::EventLoop loop_;
};