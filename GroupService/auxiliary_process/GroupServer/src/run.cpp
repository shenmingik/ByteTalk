#include "GroupServer.hpp"
#include <rpc/RpcApplication.hpp>
#include <rpc/RpcConfigure.hpp>

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcConfigure configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("server_ip");
    int port = atoi(configure.find_load("server_port").c_str());

    GroupServer server(ip, port);
    server.run();
    return 0;
}
