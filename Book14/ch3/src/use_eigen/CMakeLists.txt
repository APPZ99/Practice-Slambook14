cmake_minimum_required(VERSION 2.8)

project(UseEigen)

# 设定编译模式
set(CMAKE_BUILD_TYPE "Release")
# 设定以03级对代码进行优化
set(CMAKE_CXX_FLAGS "-O3")

include_directories(/usr/include/eigen3)
add_executable(${PROJECT_NAME} eigen_matrix.cpp)