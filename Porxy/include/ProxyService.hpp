#pragma once

#include "LogServer.pb.h"
#include "ChatServer.pb.h"
#include "UserService.pb.h"
#include "FriendService.pb.h"
#include "GroupService.pb.h"
#include "OfflineService.pb.h"

#include "Redis.hpp"
#include "ProxyServer.hpp"
#include "ZooKeeperMaster.hpp"

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>
#include <rpc/RpcControl.hpp>
#include <rpc/RpcChannel.hpp>

#include <unordered_map>
#include <functional>
#include <string>
#include <mutex>

using namespace std;
using MsgHandler = function<void(const muduo::net::TcpConnectionPtr &conn, string &recv_str, muduo::Timestamp time)>;

//单例设计
class ProxyService
{
public:
    static ProxyService &get_instance()
    {
        static ProxyService service;
        return service;
    }

public:
    //登录
    void login(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //注册
    void regist(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //注销业务
    void loginout(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //一对一聊天业务
    void one_chat(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //添加好友业务
    void add_friend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //删除好友
    void delete_friend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //获取用户信息
    void get_userInfo(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //获取好友列表
    void get_friendList(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //读取离线消息
    void read_offlineMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //创建 群组
    void create_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //加入群组
    void add_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //退出群
    void quit_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //获得群用户信息
    void get_groupUsers(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //聊天消息
    void chat_msg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    //转发而来的消息
    void convey_msg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

public:
    //获得消息对应的处理器
    MsgHandler get_handler(string msg_type);

    //处理客户端异常退出
    void client_close_exception(const muduo::net::TcpConnectionPtr &conn);

    //服务器异常，业务重置
    void reset();

private:
    ProxyService();

private:
    ProxyService(const ProxyService &) = delete;
    ProxyService &operator=(ProxyService &) = delete;

private:
    unordered_map<string, MsgHandler> msg_handler_map_; //存储事件及事件对应的回调函数

    unordered_map<int, muduo::net::TcpConnectionPtr> use_connection_map_; //存储登录用户，及对应tcpptr信息
    mutex mutex_;                                                         //保护上一个的线程安全
private:
    RedisCli redis_client_; //连接redis服务器

    ZKMatser master_; //连接zookeeper服务器
private:
    ik_GroupService::GroupServiceRpc_Stub group_stub_;
    ik_UserService::UserServiceRpc_Stub user_stub_;
    ik_FriendService::FriendServiceRpc_Stub friend_stub_;
    ik_OfflineService::OfflineServiceRpc_Stub offline_stub_;
    ik::LogServerRpc_Stub log_stub_;
};