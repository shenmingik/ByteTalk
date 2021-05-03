#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>
#include "GroupService.hpp"
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);

    RpcProvider provider;
    provider.notify_service(new GroupService);
    provider.run();
    return 0;
}