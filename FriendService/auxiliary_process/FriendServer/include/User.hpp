#pragma once

#include <string>

using namespace std;

class User
{
public:
    //设置用户id
    void set_id(int id) { id_ = id; }

    //设置用户名
    void set_name(string name) { name_ = name; }

    //获得用户id
    int get_id() { return id_; }

    //获得用户名
    string get_name() { return name_; }

private:
    int id_;
    string name_;
};