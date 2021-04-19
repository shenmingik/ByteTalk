#include "LogServer.hpp"
#include <cstdlib>
#include <ctime> // for time
#include <cstring>
#include <iostream>

#include <sys/stat.h> //for mkdir
#include <sys/types.h>

#define BUFF_SIZE 32
#define FILE_SIZE 64

//打印INFO 日志
void LogServer::Log_INFO(const char *file_path, string msg)
{
    //添加日志级别信息
    msg.insert(0, INFO.c_str());
    write_file(file_path, msg);
}

//打印INFO 日志
void LogServer::Log_ERROR(const char *file_path, string msg)
{
    //添加日志级别信息
    msg.insert(0, ERROR.c_str());
    write_file(file_path, msg);
}

//打印INFO 日志
void LogServer::Log_FATAL(const char *file_path, string msg)
{
    //添加日志级别信息
    msg.insert(0, FATAL.c_str());
    write_file(file_path, msg);
}

//向file_path 中去写日志
bool LogServer::write_file(const char *file_path, string msg)
{
    //组织文件名
    time_t now = time(nullptr);
    tm *now_time = localtime(&now);
    char file_name[FILE_SIZE] = {0};
    sprintf(file_name, "%4d-%2d-%2d_log.txt", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday);

    string file_str = file_path;
    file_str += "/";
    file_str += file_name;

    // 组织日志格式
    memset(input_str, 0, INPUT_SIZE);
    sprintf(input_str, "%2d:%2d:%2d=> ", now_time->tm_hour, now_time->tm_min, now_time->tm_sec);
    msg.insert(0, input_str);
    msg += '\n';

    FILE *fp = fopen(file_str.c_str(), "a+");
    if (fp == nullptr)
    {
        cout << "can't open file: " << file_path << endl;
        return false;
    }
    fputs(msg.c_str(), fp);
    fclose(fp);
}

void LogServer::Log_INFO(::google::protobuf::RpcController *controller,
                         const ::ik::LogRequest *request,
                         ::google::protobuf::Empty *response,
                         ::google::protobuf::Closure *done)
{
    string node_name = request->name();
    string msg = request->msg();

    //创建目录
    string dir_path = "../log/";
    dir_path += node_name;
    mkdir(dir_path.c_str(), 0777);

    //写日志
    Log_INFO(dir_path.c_str(), msg);

    done->Run();
}
void LogServer::Log_ERROR(::google::protobuf::RpcController *controller,
                          const ::ik::LogRequest *request,
                          ::google::protobuf::Empty *response,
                          ::google::protobuf::Closure *done)
{
    string node_name = request->name();
    string msg = request->msg();

    //创建目录
    string dir_path = "../log/";
    dir_path += node_name;
    mkdir(dir_path.c_str(), 0777);

    //写日志
    Log_ERROR(dir_path.c_str(), msg);

    done->Run();
}
void LogServer::Log_FATAL(::google::protobuf::RpcController *controller,
                          const ::ik::LogRequest *request,
                          ::google::protobuf::Empty *response,
                          ::google::protobuf::Closure *done)
{
    string node_name = request->name();
    string msg = request->msg();

    //创建目录
    string dir_path = "../log/";
    dir_path += node_name;
    mkdir(dir_path.c_str(), 0777);

    //写日志
    Log_FATAL(dir_path.c_str(), msg);

    done->Run();
}