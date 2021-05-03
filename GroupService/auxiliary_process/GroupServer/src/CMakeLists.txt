# 添加SRC_LIST
aux_source_directory(. SRC_LIST)

# 添加编译加入录音
add_executable(ChatServer ${SRC_LIST})

# 链接库
target_link_libraries(ChatServer protobuf src zookeeper_mt muduo_net muduo_base Pool mysqlclient pthread)