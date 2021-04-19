#pragma once
#include <string>
#include <google/protobuf/service.h>

#include "LogServer.pb.h"

#define INPUT_SIZE 128
using namespace std;

class LogServer : public ik::LogServerRpc
{
public:
    //打印INFO 日志
    void Log_INFO(const char *file_path, string msg);

    //打印INFO 日志
    void Log_ERROR(const char *file_path, string msg);

    //打印INFO 日志
    void Log_FATAL(const char *file_path, string msg);

public:
    void Log_INFO(::google::protobuf::RpcController *controller,
                  const ::ik::LogRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done);
    void Log_ERROR(::google::protobuf::RpcController *controller,
                   const ::ik::LogRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done);
    void Log_FATAL(::google::protobuf::RpcController *controller,
                   const ::ik::LogRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done);

private:
    //向file_path 中去写INFO日志
    bool write_file(const char *file_path, string msg);

private:
    string FATAL = "[FATAL]";
    string INFO = "[INFO]";
    string ERROR = "[ERROR]";
    char input_str[INPUT_SIZE] = {0};
};