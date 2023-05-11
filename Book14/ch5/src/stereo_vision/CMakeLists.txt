project(StereoVision)

add_executable(stereoVision stereo_vision.cpp)
target_link_libraries(stereoVision ${OpenCV_LIBS} ${Pangolin_LIBRARIES})