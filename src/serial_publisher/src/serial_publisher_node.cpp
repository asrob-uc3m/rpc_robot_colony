#include "ros/ros.h"
#include "serial_publisher/Motors.h"
#include <sstream>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher servo_sub = n.advertise<serial_publisher::Motors>("servo",1);
    ros::Rate loop_rate(1);

    serial_publisher::Motors msg;
    msg.data=90;
    sleep(1);


    while (ros::ok())
    {


            msg.motor_izquierdo = 50;
            msg.motor_derecho = 50;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.motor_izquierdo = 90;
            msg.motor_derecho = 90;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.motor_izquierdo = 120;
            msg.motor_derecho = 120;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);

            msg.motor_izquierdo = 90;
            msg.motor_derecho = 90;
            servo_sub.publish(msg);
            loop_rate.sleep();

            sleep(3);


    }
}
