#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatroom", 1000, messageCallback);

    ros::spin();

    return 0;
}
