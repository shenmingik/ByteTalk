# 将当前目录下所有文件添加到SRC_LIST
aux_source_directory(. SRC_LIST)

# 指定生成可执行文件
add_executable(callee ${SRC_LIST})

# 指定链接的目录
target_link_libraries(callee protobuf rpc muduo_base muduo_net pthread zookeeper_mt)