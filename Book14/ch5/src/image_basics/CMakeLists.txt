project(ImageBasics)

add_executable(imageBasics image_basics.cpp)
target_link_libraries(imageBasics ${OpenCV_LIBS})

add_executable(undistortImage undistort_image.cpp)
target_link_libraries(undistortImage ${OpenCV_LIBS})