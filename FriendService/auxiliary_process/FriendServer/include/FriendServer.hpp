#pragma once
#include "ZooKeeperFow.hpp"
#include "FriendServer.pb.h"
#include "User.hpp"

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>

#include <SQL_pool/connect_pool.hpp>
#include <SQL_pool/connect.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

class FriendServer
{
public:
    FriendServer(string ip, int port);

public:
    //服务器运行
    void run();

    //读写事件回调函数
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

    //连接事件回调函数
    void on_connect(const muduo::net::TcpConnectionPtr &conn);

public:
    //获取userid 用户的好友列表
    vector<User> get_friendlist(int userid);

    //获得userid用户信息
    User get_userinfo(int userid);

    //userid 的用户添加好友 friendid
    void add_friend(int userid, int friendid);

    //删除userid用户的好友 friendid
    void delete_friend(int userid, int friendid);

private:
    string ip_;
    int port_;

    muduo::net::EventLoop loop_;

    Connect_pool *pool_;
};