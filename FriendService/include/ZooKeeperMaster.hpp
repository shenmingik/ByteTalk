#pragma once

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>

#include <zookeeper/zookeeper.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <semaphore.h>

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <map>

using namespace std;

class ZKMatser
{
public:
    ZKMatser(string path);
    ~ZKMatser();

    //和zkserver 连接
    bool start();

    //在zkserver 根据指定的path创建znode节点
    bool create_master(string master_name);

    //每秒更新服务列表
    void get_follow();

    //得到znode节点对应的data值
    string get_znode_data(string path);

    //得到一个可用服务节点，并与之创建一个文件描述符,返回文件描述符
    int get_service();

private:
    zhandle_t *zkhandle_;
    map<string, string> followers_; //存储从节点

    int current_service_; //当前该是哪个节点服务
    int total_services_;  //总共有多少节点服务

    string path_;   //当前服务路径

    mutex mutex_;
};