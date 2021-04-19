#include "LogServer.hpp"

#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>
#include <rpc/RpcControl.hpp>

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);

    RpcProvider provider;
    provider.notify_service(new LogServer);
    provider.run();
    return 0;
}