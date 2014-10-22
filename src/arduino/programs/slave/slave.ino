/**
 * @file    slave.ino
 * @brief   set robot in slave mode and move it according received data
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#include <Bluetooth.h>
#include <Robot.h>
#include <Servomotor.h>
#include <UltrasonicSensor.h>
#include <Ultrasonic.h>
#include <Servo.h>


Robot my_bot(2,10,9);//don't need US

void setup()
{
    Serial.begin(38400);
}
void loop()
{  
    if (Serial.available())//if data received
    {
        char tmpChar = Serial.read();
        switch(tmpChar)
        {
            case '0':
                my_bot.stop_robot();//stop the robot
                break;
            case '1':
                my_bot.move_back(2);//move the robot back-speed 2
                break;
            case'2':
                my_bot.turn_left(4);//turn the robot left-speed 4
                break;
            case'3':
                my_bot.turn_right(4);//turn the robot right-speed 4
                break;
            case'4':
                my_bot.turn_left(2);//turn the robot left-speed 2
                break;
            case'5':
                my_bot.turn_right(2);//turn the robot right-speed 2
                break;
            case'6':
                my_bot.move_forward(4);//move the robot forward-speed 4
                break;
            default:
                break;
        }
    }
}




