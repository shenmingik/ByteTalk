#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>
#include "OfflineService.hpp"
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);

    RpcProvider provider;
    provider.notify_service(new OfflineService);
    provider.run();
    return 0;
}