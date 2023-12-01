#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <thread>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
using namespace std;
  ros::Publisher path_pub; 
  nav_msgs::Path path;

void gt_path_callback(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
  // 创建并填充nav_msgs::Path消息
  //Create and fill nav_ Msgs:: Path Message
  path.header = msg->header;
  path.header.frame_id = "camera_link";
  path.poses.push_back(*msg);
cout<<"The program is reading data.stamp:"<<msg->header.stamp<<endl;
  // 发布nav_msgs::Path消息
  //Publish Nav_ Msgs:: Path Message
  path_pub.publish(path);
}


void publishTf()
{
  ros::NodeHandle nh;
  tf2_ros::TransformBroadcaster broadcaster;

  while (ros::ok())
  {
  // 创建并设置tf2变换消息
  //Create and set tf2 transformation messages
  geometry_msgs::TransformStamped transformStamped;
  transformStamped.header.frame_id = "base_link";
  transformStamped.child_frame_id = "camera_link";
  transformStamped.transform.translation.x = 0;
  transformStamped.transform.translation.y = 0.0;
  transformStamped.transform.translation.z = 0;
  transformStamped.transform.rotation.x = 0.0;
  transformStamped.transform.rotation.y = 0.0;
  transformStamped.transform.rotation.z = 0.0;
  transformStamped.transform.rotation.w = 1.0;

  ros::Rate rate(10.0);  // 发布频率为10Hz.The publishing frequency is 10Hz
    transformStamped.header.stamp = ros::Time::now();
    broadcaster.sendTransform(transformStamped);

    ros::Rate(10).sleep();
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "tf_and_dataset_publisher");
  ros::NodeHandle nh;
  ros::Subscriber sub_lidar = nh.subscribe("/gt_traj", 100,gt_path_callback);
  // 创建一个发布器，用于发布nav_msgs::Path消息
  //Create a publisher for publishing nav_ Msgs:: Path Message
  path_pub = nh.advertise<nav_msgs::Path>("path_topic", 10);

  std::thread tf_thread(&publishTf);

  ros::spin();
  cout<<"Program startup completed"<<endl;

  tf_thread.join();

  return 0;
}


