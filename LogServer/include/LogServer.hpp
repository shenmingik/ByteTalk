#pragma once
#include <string>

#define INPUT_SIZE 128
using namespace std;
class LogServer
{
public:
    static LogServer &get_instance()
    {
        static LogServer server;
        return server;
    }

public:
    //打印INFO 日志
    void Log_INFO(const char *file_path, string msg);

    //打印INFO 日志
    void Log_ERROR(const char *file_path, string msg);

    //打印INFO 日志
    void Log_FATAL(const char *file_path, string msg);

private:
    //向file_path 中去写INFO日志
    bool write_file(const char *file_path, string msg);

private:
    LogServer(){};

private:
    static string INFO;
    static string ERROR;
    static string FATAL;

    static char input_str[INPUT_SIZE];
};