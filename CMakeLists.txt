cmake_minimum_required(VERSION 2.8.3)
set(CMAKE_CXX_STANDARD 11)

project(showpath_bag)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf2_ros
  nav_msgs
  geometry_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(read_path src/read_path.cpp)
target_link_libraries(read_path ${catkin_LIBRARIES})

