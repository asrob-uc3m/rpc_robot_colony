#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include <sstream>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher servo_sub = n.advertise<std_msgs::UInt16>("servo",1);
    ros::Rate loop_rate(1);

    std_msgs::UInt16 msg;
    msg.data=90;
    sleep(1);


    while (ros::ok())
    {

            msg.data=50;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.data=90;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.data=150;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.data=90;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);


    }
}
