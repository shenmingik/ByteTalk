#include "ZooKeeperFow.hpp"
#include "GroupServer.pb.h"
#include "User.hpp"

#include <SQL_pool/connect_pool.hpp>

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>

#include <string>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class GroupServer
{
public:
    //将userid所代表的用户添加到groupid的群里
    bool add_group(int userid, int groupid);

    //创建群，群名为group_name,返回群号
    int create_group(int userid, string group_name);

    //在groupid的群里删除userid这一列
    bool quit_group(int userid, int groupid);

    //得到群组里所有用户的信息
    vector<User> get_group_users(int groupid);

private:
    ZKClient zk_client_;

    Connect_pool *pool_;
};