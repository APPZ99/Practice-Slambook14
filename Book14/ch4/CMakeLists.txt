cmake_minimum_required(VERSION 2.8)

project(UseSophus)

find_library(Sophus REQUIRED)

include_directories("/usr/include/eigen3")
include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable(useSophus use_sophus.cpp)
# 在原书基础上加上下面这句
target_link_libraries(useSophus ${Sophus_LIBRARIES})

# 添加子目录
add_subdirectory(example)