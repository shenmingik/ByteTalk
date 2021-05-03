#include "ZooKeeperMaster.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

ZKMatser::ZKMatser(string path) : zkhandle_(nullptr)
{
    current_service_ = 0;
    path_ = path;
}
ZKMatser::~ZKMatser()
{
    if (zkhandle_ != nullptr)
    {
        zookeeper_close(zkhandle_);
    }
}

//和zkserver 连接
bool ZKMatser::start()
{
    RpcConfigure &configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("zookeeper_ip");
    string host = configure.find_load("zookeeper_port");

    string conn_str = ip + ":" + host;
    cout << conn_str << endl;
    zkhandle_ = zookeeper_init(conn_str.c_str(), init_watcher, 30000, 0, nullptr, 0);
    if (zkhandle_ == nullptr)
    {
        return false;
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(zkhandle_, &sem);

    sem_wait(&sem); //等待信号，再进行下一步

    //初始化节点信息
    get_follow();

    return true;
}

//在zkserver 根据指定的path创建znode节点
bool ZKMatser::create_master(string master_name)
{
    string path = "/" + master_name;
    char path_buffer[BUFF_SIZE] = {0};
    int buff_len = sizeof(path_buffer);

    int flag = zoo_create(zkhandle_, path.c_str(), "", 0, &ZOO_OPEN_ACL_UNSAFE, 0, path_buffer, buff_len);
    if (flag == ZOK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//每秒更新服务列表
void ZKMatser::get_follow()
{

    if (zkhandle_ == nullptr)
        cout << "zkhand is null" << endl;
    String_vector followers;
    zoo_get_children(zkhandle_, path_.c_str(), 0, &followers);

    map<string, string> temp;
    total_services_ = followers.count;
    cout << "count:" << followers.count << endl;

    for (int i = 0; i < followers.count; i++)
    {
        cout << followers.data[i] << endl;
        string znode_name = followers.data[i];
        string znode_path = path_ + "/" + znode_name;
        string ip_port = get_znode_data(znode_path);
        temp[znode_name] = ip_port;
    }
    {
        unique_lock<mutex> lock(mutex_);
        followers_.swap(temp);
    }
}

//得到znode节点对应的data值
string ZKMatser::get_znode_data(string path)
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

//得到一个可用服务节点，并与之创建一个文件描述符,返回文件描述符
int ZKMatser::get_service()
{
    if (total_services_ == 0)
        return -1;

    string host_data;
    {
        unique_lock<mutex> lock(mutex_);
        //获取当前应该服务的节点
        auto it = followers_.begin();
        for (int i = 0; i < current_service_; i++)
        {
            it++;
        }
        current_service_ = (current_service_ + 1) % (total_services_ + 1);

        host_data = it->second;
    }

    int host_index = host_data.find(":");
    if (host_index == -1)
    {
        return -1;
    }
    //取得ip 和 port
    string ip = host_data.substr(0, host_index);
    uint16_t port = atoi(host_data.substr(host_index + 1, host_data.size() - host_index).c_str());

    //建立套接字并连接
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        close(client_fd);
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        close(client_fd);
        return -1;
    }
    else
    {
        return client_fd;
    }
}