#include "Redis.hpp"
#include <iostream>

using namespace std;
int main()
{
    RedisCli client("127.0.0.1", 6379);
    client.connect();
    client.set_host(1, "127.0.0.1:6004");
}