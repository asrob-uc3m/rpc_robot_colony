#include "ros/ros.h"
#include "std_msgs/Int16.h"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_to_servo");
  ros::NodeHandle n;


  ros::Publisher pub_to_servo = n.advertise<std_msgs::Int16>("servo_msg", 1);
  ros::Rate loop_rate(10);
  ros::Rate loop_rate2(1);

  std_msgs::Int16 msg;
  int index=0;
  while (ros::ok())
  {
    if(index>180)
    {
        msg.data = 90;
        pub_to_servo.publish(msg);
        loop_rate2.sleep();
        index = 0;
    }
        msg.data = index;
        pub_to_servo.publish(msg);
        loop_rate.sleep();
        index ++;
  }
  return 0;
}
