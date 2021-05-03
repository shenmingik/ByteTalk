#include "OfflineServer.pb.h"

#include "ZooKeeperFow.hpp"

#include <muduo/net/Buffer.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Timestamp.h>

#include <SQL_pool/connect_pool.hpp>

#include <string>
#include <vector>
#include <memory>
using namespace std;

class OfflineServer
{
public:
    //初始化配置等信息
    OfflineServer(string ip, int port);

    //开始服务
    void run();

    //读写事件回调函数
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

    //连接事件回调函数
    void on_connect(const muduo::net::TcpConnectionPtr &conn);

public:
    //写离线消息
    bool write_offlineMsg(int friend_id, string msg);
    //读离线消息
    vector<string> read_offlineMsg(int myid);

private:
    string ip_; //服务器ip和port
    int port_;

    muduo::net::EventLoop loop_; //main事件循环

    ZKClient zk_client_; //zkclient客户端

    Connect_pool *pool_; //连接池
};