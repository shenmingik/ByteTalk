#include "LogSend.hpp"
#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>
#include <cstdlib>

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcConfigure &configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("LogSend_ip");
    int port = atoi(configure.find_load("LogSend_port").c_str());

    LogSend server;
    server.run(ip, port);
    return 0;
}