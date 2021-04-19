#include "LogServer.hpp"
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    LogServer &server = LogServer::get_instance();
    server.Log_FATAL("../log/User","lalala");
}