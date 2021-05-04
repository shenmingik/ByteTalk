#include <signal.h>

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>

#include "ProxyService.hpp"
using namespace std;

//处理服务器ctrl+c结束后，重置user的状态信息
void reset_handler(int)
{
    ProxyService::get_instance().reset();
    exit(0);
}

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcConfigure configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("server_ip");
    int port = atoi(configure.find_load("server_port").c_str());

    signal(SIGINT, reset_handler);

    //初始化zookeeper的连接
    ProxyService::get_instance();
    
    muduo::net::EventLoop loop;
    muduo::net::InetAddress addr(ip, port);
    ProxyServer server(loop, addr, "ProxyServer");

    server.start();
    loop.loop();

    return 0;
}