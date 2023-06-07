#include "ros/ros.h"  // ROS Default Header File
#include "ros_tutorials_topic/MsgTutorial.h"  // MsgTutorial Message File Header. The header file is automatically created when building the package.
#include "geometry_msgs/PoseArray.h"
int main(int argc, char** argv)  // Node Main Function
{
    ros::init(argc, argv, "topic_publisher");  // Initializes Node Name
    ros::NodeHandle nh;                        // Node handle declaration for communication with ROS system

    // Declare publisher, create publisher 'ros_tutorial_pub' using the 'MsgTutorial'
    // message file from the 'ros_tutorials_topic' package. The topic name is
    // 'ros_tutorial_msg' and the size of the publisher queue is set to 100.
    ros::Publisher ros_tutorial_pub = nh.advertise<geometry_msgs::PoseArray>("ros_tutorial_msg", 100);

    // Set the loop period. '10' refers to 10 Hz and the main loop repeats at 0.1 second intervals
    ros::Rate loop_rate(25);

    geometry_msgs::PoseArray msg;  // Declares message 'msg' in 'MsgTutorial' message file format
    int count = 0;                 // Variable to be used in message

    while (ros::ok()) {
        msg.header.stamp = ros::Time::now();  // Save current time in the stamp of 'msg'
        for (unsigned int i = 0; i < 40; i++) {
            geometry_msgs::Pose pose;
            pose.position.x = 1.5;
            pose.position.y = 1.4 + i / 100;
            pose.position.z = 0.14 + i / 1000;
            msg.poses.push_back(pose);
        }

        // Prints the 'data' message

        ros_tutorial_pub.publish(msg);  // Publishes 'msg' message

        loop_rate.sleep();  // Goes to sleep according to the loop rate defined above.

        ++count;  // Increase count variable by one
    }

    return 0;
}
