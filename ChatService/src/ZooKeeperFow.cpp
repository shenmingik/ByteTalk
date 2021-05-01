#include "ZooKeeperFow.hpp"
#include <iostream>
#define BUFF_SIZE 128

//zk_init 函数的异步回调函数
void init_watcher(zhandle_t *handler, int type, int state, const char *path, void *watcher_context)
{
    if (type == ZOO_SESSION_EVENT)
    {
        if (state == ZOO_CONNECTED_STATE) //连接成功,发送一个信号
        {
            sem_t *sem = (sem_t *)zoo_get_context(handler);
            sem_post(sem);
        }
    }
}

ZKClient::ZKClient() : zkhandle_(nullptr)
{
}
ZKClient::~ZKClient()
{
    if (zkhandle_ != nullptr)
    {
        zookeeper_close(zkhandle_);
    }
}

//和zkserver 连接
bool ZKClient::start()
{
    RpcConfigure &configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("zookeeper_ip");
    string host = configure.find_load("zookeeper_port");

    string conn_str = ip + ":" + host;
    zkhandle_ = zookeeper_init(conn_str.c_str(), init_watcher, 300000, 0, nullptr, 0);
    if (zkhandle_ == nullptr)
    {
        return false;
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(zkhandle_, &sem);

    sem_wait(&sem); //等待信号，再进行下一步
    return true;
}

//在zkserver 根据指定的path创建znode节点
bool ZKClient::create(string &path, const char *data, int data_len, int state)
{
    char path_buffer[BUFF_SIZE] = {0};
    int buff_len = sizeof(path_buffer);
    int tail = 1;

    string tail_str;
    tail_str = path + to_string(tail);

    //检查path是否存在
    while (zoo_exists(zkhandle_, tail_str.c_str(), 0, nullptr) != ZNONODE)
    {
        tail_str = path + to_string(++tail);
    }

    int flag = zoo_create(zkhandle_, tail_str.c_str(), data, data_len, &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, buff_len);
    if (flag == ZOK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//根据参数路径获得值
string ZKClient::get_data(string path)
{
    char buf[BUFF_SIZE] = {0};
    int buffer_len = sizeof(buf);

    int flag = zoo_get(zkhandle_, path.c_str(), 0, buf, &buffer_len, nullptr);
    if (flag == ZOK)
    {
        return buf;
    }
    else
    {
        return "";
    }
}