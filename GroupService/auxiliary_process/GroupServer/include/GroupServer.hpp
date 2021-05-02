#include "ZooKeeperFow.hpp"
#include "GroupServer.pb.h"
#include "User.hpp"

#include <SQL_pool/connect_pool.hpp>

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>

#include <string>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class GroupServer
{
public:
    //初始化server信息
    GroupServer(string ip, int port);

    //开始运行服务
    void run();

    //绑定连接事件
    void on_connet(const muduo::net::TcpConnectionPtr &conn);

    //绑定连接读写事件
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

public:
    //将userid所代表的用户添加到groupid的群里
    bool add_group(int userid, int groupid);

    //创建群，群名为group_name,返回群号
    int create_group(int userid, string group_name);

    //在groupid的群里删除userid这一列
    bool quit_group(int userid, int groupid);

    //得到群组里所有用户的信息
    vector<User> get_group_users(int groupid);

private:
    string ip_; //IP地址
    int port_;  //端口号

    muduo::net::EventLoop loop_; //muduo事件循环

    ZKClient zk_client_; //和zookeeper的连接句柄

    Connect_pool *pool_; //指向连接池的指针
};