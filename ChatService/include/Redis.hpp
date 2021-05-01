#pragma once

#include <hiredis/hiredis.h>

#include <string>

using namespace std;

class RedisCli
{
public:
    //初始化redis连接信息
    RedisCli(string ip,int port);

    //释放连接
    ~RedisCli();

    //初始化get_channel、set_channel连接
    bool connect();

    //判断某个账号是否在线
    bool is_exist(int id);

    //根据账户得到它上线的服务器
    string get_host(int id);

    //设置账户及其登录的服务器
    bool set_host(int id,string host);
private:
    redisContext* get_channel_;
    redisContext* set_channel_;

    string ip_;
    int port_;
};