#pragma once

#include "ZooKeeperFow.hpp"
#include "Redis.hpp"
#include "LogServer.pb.h"
#include "ChatServer.pb.h"
#include "ProxyServer.pb.h"
#include "OfflineService.pb.h"

#include <google/protobuf/empty.pb.h>
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcControl.hpp>

#include <muduo/net/EventLoop.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/TcpServer.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/TcpConnection.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unordered_map>
#include <functional>
#include <string>

using namespace std;
class ChatServer
{
public:
    ChatServer(string redis_ip, int redis_port);

    //开启服务
    void run(string ip, int port);

    //连接事件回调函数
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

    //连接事件回调函数
    void on_connect(const muduo::net::TcpConnectionPtr &conn);

    //根据host建立连接
    int establish_connection(string host);

private:
    ZKClient zk_client_;
    RedisCli redis_client_;

    muduo::net::EventLoop loop_;

    //存储抽象服务节点chatservice及与其连接对应的socket
    unordered_map<string, int> channel_map_;

    ik::LogServerRpc_Stub stub_;
    ik_OfflineService::OfflineServiceRpc_Stub offline_stub_;
};