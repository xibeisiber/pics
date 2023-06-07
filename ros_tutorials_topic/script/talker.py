#! /home/jia/miniconda3/bin/python3
# license removed for brevity
import rospy
import numpy as np
from geometry_msgs.msg import PoseArray
from geometry_msgs.msg import Pose

def talker():
	pub = rospy.Publisher('ros_tutorial_msg', PoseArray, queue_size=10)
	rospy.init_node('talker', anonymous=True)
	fs=40
	rate = rospy.Rate(1000/fs) # 10hz
	while not rospy.is_shutdown():
		blockerposearray = PoseArray() # 计算frame_skip内的所有目标位姿并发送出去
		blockerposearray.header.stamp = rospy.Time.now()
		for i in range(fs):
			outpose = Pose()
			outpose.position.x = 1.5
			outpose.position.y = 1.4 + i / 100;
			outpose.position.z = 0.14 + i / 1000;
			blockerposearray.poses.append(outpose)
		pub.publish(blockerposearray)
		rate.sleep()

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass