# 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(ch3)

# 设定编译模式
set(CMAKE_BUILD_TYPE "Debug")

# 添加子工程
add_subdirectory(src/use_eigen)

