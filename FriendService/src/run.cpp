#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>

#include "FriendService.hpp"

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcProvider provider;
    provider.notify_service(new FriendService);
    provider.run();
    return 0;
}