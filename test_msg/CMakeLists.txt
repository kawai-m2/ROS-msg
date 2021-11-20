cmake_minimum_required(VERSION 3.0.2)
project(test_msg)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  test.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
LIBRARIES msg
CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)


include_directories( ${catkin_INCLUDE_DIRS} )


add_executable(pub src/pub.cpp)
add_dependencies(pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pub ${catkin_LIBRARIES} )

add_executable(sub src/sub.cpp)
add_dependencies(sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sub ${catkin_LIBRARIES} )
