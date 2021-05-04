#pragma once

#include <muduo/net/Buffer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Timestamp.h>

#include <string>

using namespace std;

class PoxryServer
{
public:
    //初始化服务器信息
    PoxryServer(muduo::net::EventLoop &loop, string ip, int port, string name);

    //连接事件的回调函数
    void on_connet(const muduo::net::TcpConnectionPtr& conn);

    //读写事件回调函数
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

private:
    muduo::net::TcpServer server_; //server对象

    muduo::net::EventLoop &loop_; //main loop
};