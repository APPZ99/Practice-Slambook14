cmake_minimum_required(VERSION 2.8)

project(Examples)

# include_directories(/usr/include/eigen3)

# add_executable(CoordinateTransform coordinate_transform.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(PlotTrajectory plot_trajectory.cpp)
target_link_libraries(PlotTrajectory ${Pangolin_LIBRARIES})

