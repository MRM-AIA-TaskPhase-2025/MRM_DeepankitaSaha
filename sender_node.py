#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def sender():
    rospy.init_node('sender_node', anonymous=True)
    pub = rospy.Publisher('chatroom', String, queue_size=10)
    rate = rospy.Rate(1)  # 1 message per second

    while not rospy.is_shutdown():
        message = raw_input("Type your message: ")
        pub.publish(message)
        rate.sleep()

if __name__ == '__main__':
    try:
        sender()
    except rospy.ROSInterruptException:
        pass

