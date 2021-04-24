#include "UserService.hpp"

#include <rpc/RpcProvider.hpp>
#include <rpc/RpcApplication.hpp>
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    RpcProvider provider;
    provider.notify_service(new UserService);
    provider.run();
    return 0;
}