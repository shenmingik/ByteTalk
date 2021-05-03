cmake_minimum_required(VERSION 3.0)
project(GroupService)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAG} -g)

# 设置输出文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/auxiliary_process/GroupServer/include)

add_subdirectory(src)
add_subdirectory(auxiliary_process)