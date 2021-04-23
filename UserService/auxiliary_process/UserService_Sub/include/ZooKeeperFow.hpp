#pragma once

#include <zookeeper/zookeeper.h>

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>

#include <semaphore.h>
#include <string>

using namespace std;

class ZKClient
{
public:
    ZKClient();
    ~ZKClient();

    //和zkserver 连接
    bool start();

    //在zkserver 根据指定的path创建znode节点
    bool create(string &path, const char *data, int data_len, int state = 0);

    //根据参数路径获得值
    string get_data(string path);

private:
    zhandle_t *zkhandle_;
};
