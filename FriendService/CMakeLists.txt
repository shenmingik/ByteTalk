cmake_minimum_required(VERSION 3.0)
project(FriendService)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置可执行文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/auxiliary_process/FriendServer/include)

# 设置子目录
add_subdirectory(src)
add_subdirectory(auxiliary_process)
add_subdirectory(example)