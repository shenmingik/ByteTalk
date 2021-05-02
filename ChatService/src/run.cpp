#include "ChatServer.hpp"
#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcConfigure configure = RpcApplication::get_instance().get_configure();
    string redis_ip = configure.find_load("redis_ip");
    int redis_port = atoi(configure.find_load("redis_port").c_str());
    string ip = configure.find_load("server_ip");
    int port = atoi(configure.find_load("server_port").c_str());

    ChatServer server(redis_ip, redis_port);
    server.run(ip, port);
}