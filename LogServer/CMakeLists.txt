cmake_minimum_required(VERSION 3.0)
project(LogServer)
# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置可执行文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/auxiliary_process/download/include)

# 设置项目库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/thirdlib)

add_subdirectory(src)
add_subdirectory(auxiliary_process)
