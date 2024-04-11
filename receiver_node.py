#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo("Message received: %s", data.data)

def receiver():
    rospy.init_node('receiver_node', anonymous=True)
    rospy.Subscriber('chatroom', String, callback)
    rospy.spin()

if __name__ == '__main__':
    receiver()

