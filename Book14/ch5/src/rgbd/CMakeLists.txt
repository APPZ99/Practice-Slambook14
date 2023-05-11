project(rgbd)

add_executable(joinMap join_map.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES})