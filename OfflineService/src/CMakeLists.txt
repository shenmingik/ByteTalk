# 添加当前路径的文件到SRC_LIST 变量
aux_source_directory(. SRC_LIST)

# 生成可执行文件
add_executable(OfflineService ${SRC_LIST})

# 链接库
target_link_libraries(OfflineService protobuf rpc zookeeper_mt muduo_net muduo_base pthread)