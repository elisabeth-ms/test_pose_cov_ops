cmake_minimum_required(VERSION 2.8.3)
project(test_pose_cov_ops)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	tf
        geometry_msgs
        mrpt_bridge
        pose_cov_ops)

find_package(MRPT REQUIRED)


catkin_package(
CATKIN_DEPENDS roscpp tf mrpt_bridge pose_cov_ops)


include_directories(${catkin_INCLUDE_DIRS})


add_executable(${PROJECT_NAME}_node src/test_pose_cov_ops_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
   ${MRPT_LIBRARIES} ${catkin_LIBRARIES})




