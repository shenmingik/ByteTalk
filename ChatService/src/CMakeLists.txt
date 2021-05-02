# 添加当前路径下所有文件到SRC_LIST
aux_source_directory(. SRC_LIST)

# 生成可执行文件
add_executable(ChatService ${SRC_LIST})

target_link_libraries(ChatService protobuf rpc zookeeper_mt hiredis muduo_base muduo_net pthread Pool mysqlclient)