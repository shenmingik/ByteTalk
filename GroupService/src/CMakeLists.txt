# 添加SRC_LIST
aux_source_directory(. SRC_LIST)

# 添加编译加入路径
add_executable(GroupService ${SRC_LIST})

# 链接库
target_link_libraries(GroupService protobuf rpc zookeeper_mt muduo_net muduo_base Pool pthread)