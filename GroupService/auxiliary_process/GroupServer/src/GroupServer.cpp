#include "GroupServer.hpp"

#define BUFF_SIZE 128

//将userid所代表的用户添加到groupid的群里
bool GroupServer::add_group(int userid, int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into GroupUser values(%d,%d)", userid, groupid);
    return conn->update(sql);
}

//创建群，群名为group_name,返回群号
int GroupServer::create_group(int userid, string group_name)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织并执行sql语句
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into AllGroup(groupname) values('%s')", group_name);
    conn->update(sql);

    return mysql_insert_id(conn->get_connection());
}

//在groupid的群里删除userid这一列
bool GroupServer::quit_group(int userid, int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from GroupUser where userid=%d and groupid=%d", userid, groupid);
    return conn->update(sql);
}

//得到群组里所有用户的信息
vector<User> GroupServer::get_group_users(int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select User.id,User.name from User,GroupUser where GroupUser.groupid=%d and GroupUser.userid=User.id", groupid);
    MYSQL_RES *res = conn->query(sql);
    MYSQL_ROW row;

    vector<User> ret;
    while (row = mysql_fetch_row(res))
    {
        User user;
        user.set_id(atoi(row[0]));
        user.set_name(row[1]);
        ret.push_back(user);
    }

    mysql_free_result(res);
    return ret;
}