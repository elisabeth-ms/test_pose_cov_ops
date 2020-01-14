#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <pose_cov_ops/pose_cov_ops.h>



int main(int argc, char **argv)
{

  ros::init(argc, argv, "test_pose_cov_ops");

  ros::NodeHandle nh;

  geometry_msgs::PoseWithCovariance p1, p2, p3, p4;

  p1.pose.position.x = -0.3333300000;
  p1.pose.position.y = 0.0;
  p1.pose.position.z =  0.1;

  p1.pose.orientation.x = 0.7071067811;
  p1.pose.orientation.y = -0.0000003605;
  p1.pose.orientation.z = 0.7071067812;
  p1.pose.orientation.w = 0.0000048342;

  p1.covariance =  { 0.1, 0  , 0  , 0, 0, 0,
                     0  , 0.05, 0  , 0, 0, 0,
                     0  , 0  , 0.05, 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0};

  p2.pose.position.x = 1.26;
  p2.pose.orientation.w = 1.0;
  p2.covariance =  { 0.2, 0  , 0  , 0, 0, 0,
                     0  , 0.15, 0  , 0, 0, 0,
                     0  , 0  , 0.15, 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0};

  p3.pose.position.x = -0.3333300000;
  p3.pose.position.y =  0.087;
  p3.pose.position.z =  -0.050;

  p3.pose.orientation.x = 0.3535525094;
  p3.pose.orientation.y = 0.6123729444;
  p3.pose.orientation.z = 0.3535563838;
  p3.pose.orientation.w =  0.6123707076;

  p4.pose.position.x = -0.3333300000;
  p4.pose.position.y = -0.087;
  p4.pose.position.z =  -0.05;

  p4.pose.orientation.x = 0.0;
  p4.pose.orientation.y = -0.70711;
  p4.pose.orientation.z = 0.0;
  p4.pose.orientation.w = 0.70711;

  p4.covariance =  { 0.1, 0  , 0  , 0, 0, 0,
                     0  , 0.05, 0  , 0, 0, 0,
                     0  , 0  , 0.05, 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0,
                     0  , 0  , 0  , 0, 0, 0};



  geometry_msgs::PoseWithCovariance p1p2, p4p2, p1p3, p4p3;

  pose_cov_ops::compose(p1,p2,p1p2);



  ROS_INFO("p1: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p1.pose.position.x, p1.pose.position.y, p1.pose.position.z, p1.pose.orientation.x,
           p1.pose.orientation.y, p1.pose.orientation.z, p1.pose.orientation.w);


  ROS_INFO("p2: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p2.pose.position.x, p2.pose.position.y, p2.pose.position.z, p2.pose.orientation.x,
           p2.pose.orientation.y, p2.pose.orientation.z, p2.pose.orientation.w);


  ROS_INFO("p1 (+) p2: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p1p2.pose.position.x, p1p2.pose.position.y, p1p2.pose.position.z, p1p2.pose.orientation.x,
           p1p2.pose.orientation.y, p1p2.pose.orientation.z, p1p2.pose.orientation.w);


  ROS_INFO(" WRONG! p1 (+) p2: Position [-0.3333300000, -0.0000000000, -1.1600000000] Rotation: [x: 0.7071067812, y: 0.0000048342, z: -0.7071067812, w: 0.0000048342]");

  pose_cov_ops::compose(p4,p2,p4p2);


  ROS_INFO("p4: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p4.pose.position.x, p4.pose.position.y, p4.pose.position.z, p4.pose.orientation.x,
           p4.pose.orientation.y, p4.pose.orientation.z, p4.pose.orientation.w);


  ROS_INFO("p2: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p2.pose.position.x, p2.pose.position.y, p2.pose.position.z, p2.pose.orientation.x,
           p2.pose.orientation.y, p2.pose.orientation.z, p2.pose.orientation.w);

  ROS_INFO("p4 (+) p2: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p4p2.pose.position.x, p4p2.pose.position.y, p4p2.pose.position.z, p4p2.pose.orientation.x,
           p4p2.pose.orientation.y, p4p2.pose.orientation.z, p4p2.pose.orientation.w);

  ROS_INFO("[ WRONG! p4 (+) p2: Position [-0.3333300000, -0.0870000000, -1.3100000000] Rotation: [x: 0.0000000000, y: 0.7071067812, z: 0.0000000000, w: 0.7071067812]");

  pose_cov_ops::compose(p1,p3,p1p3);


  ROS_INFO("p1: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p1.pose.position.x, p1.pose.position.y, p1.pose.position.z, p1.pose.orientation.x,
           p1.pose.orientation.y, p1.pose.orientation.z, p1.pose.orientation.w);

  ROS_INFO("p3: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p3.pose.position.x, p3.pose.position.y, p3.pose.position.z, p3.pose.orientation.x,
           p3.pose.orientation.y, p3.pose.orientation.z, p3.pose.orientation.w);

  ROS_INFO("p1 (+) p3: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p1p3.pose.position.x, p1p3.pose.position.y, p1p3.pose.position.z, p1p3.pose.orientation.x,
           p1p3.pose.orientation.y, p1p3.pose.orientation.z, p1p3.pose.orientation.w);

  ROS_INFO("WRONG! p1 (+) p3: Position [-0.2833288104, -0.0869993163, 0.4333300000] Rotation: [x: 0.8660279598, y: -0.4999955728, z: 0.0000015817, w: 0.0000027396]");

  pose_cov_ops::compose(p4,p3,p4p3);


  ROS_INFO("p4: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p4.pose.position.x, p4.pose.position.y, p4.pose.position.z, p4.pose.orientation.x,
           p4.pose.orientation.y, p4.pose.orientation.z, p4.pose.orientation.w);


  ROS_INFO("p3: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p3.pose.position.x, p3.pose.position.y, p3.pose.position.z, p3.pose.orientation.x,
           p3.pose.orientation.y, p3.pose.orientation.z, p3.pose.orientation.w);

  ROS_INFO("p4 (+) p3: Position [%0.10f, %0.10f, %0.10f] Rotation: [x: %0.10f, y: %0.10f, z: %0.10f, w: %0.10f]",
           p4p3.pose.position.x, p4p3.pose.position.y, p4p3.pose.position.z, p4p3.pose.orientation.x,
           p4p3.pose.orientation.y, p4p3.pose.orientation.z, p4p3.pose.orientation.w);

  ROS_INFO("WRONG! p4 (+) p3: Position [-0.3833300000, 0.0000000000, 0.2833300000] Rotation: [x: 0.5000014934, y: 0.8660245415, z: 0.0000027396, w: -0.0000015816]");


  return 0;
}
