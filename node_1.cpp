// user_node_1.cpp
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
#include <thread>

std::string username;

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("%s", msg->data.c_str());
}

void publishMessages(ros::Publisher pub) {
    ros::Rate loop_rate(10);
    std::cout << "[" << username << "] Type your messages here: \n";
    while (ros::ok()) {
        std_msgs::String msg;
        std::string input_msg;
        std::getline(std::cin, input_msg);
        msg.data = "[" + username + "] " + input_msg;
        pub.publish(msg);
        loop_rate.sleep();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "user1");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatroom", 1000, messageCallback);
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatroom", 1000);
    

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    while (username.empty()) {
        std::cout << "Username cannot be empty. Please enter your username: ";
        std::getline(std::cin, username);
    }

    std::thread pub_thread(publishMessages, pub);

    ros::spin();

    pub_thread.join();

    return 0;
}
