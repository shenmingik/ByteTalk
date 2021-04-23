#pragma once
#include "LogServer.pb.h"
#include "UserServer.pb.h"

#include "ZooKeeperFow.hpp"

#include <SQL_pool/connect_pool.hpp>

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcControl.hpp>
#include <rpc/RpcChannel.hpp>

#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Timestamp.h>


#include <string>
#include <memory>
#include <functional>

using namespace std;
class UserServer
{
public:
    UserServer(string ip,int port);

    //服务启动
    void run();

    //读写事件回调函数
    void msg_callback(const muduo::net::TcpConnectionPtr& conn,muduo::net::Buffer* buffer,muduo::Timestamp stamp);

    //连接事件回调函数
    void conn_callback(const muduo::net::TcpConnectionPtr& conn);
public:
    //登录
    bool Login(int id, string password);

    //注销
    void LoginOut(int id);

    //注册 成功返回注册的账户，失败返回-1
    int Register(string name, string password);

public:
    string ip_;
    int port_;

    Connect_pool *pool_; //数据库连接池
    muduo::net::EventLoop loop_;
    
    ik::LogServerRpc_Stub stub_;
};
