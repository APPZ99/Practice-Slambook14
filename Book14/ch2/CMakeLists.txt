# 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 声明工程
project(HelloSLAM)

# 设定编译模式
set(CMAKE_BUILD_TYPE "Debug")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设定头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include/)

# 添加可执行程序
# add_executable(helloSLAM src/hello_slam.cpp)

# # 添加hello库
# add_library(hello src/lib_hello_slam.cpp)
# 共享库  SHARED
add_library(hello_shared SHARED src/lib_hello_slam.cpp)

# 添加可执行程序
add_executable(useHello src/use_hello.cpp)
# 库文件链接到执行程序
target_link_libraries(useHello hello_shared)
