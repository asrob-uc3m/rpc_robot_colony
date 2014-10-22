/**
 * @file    Movemment_test.h
 * @brief   movemment test
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

Robot my_bot(1,10,9,5,7,6,8,3,4);

void setup()
{
    Serial.begin(38400);
}
void loop()
{  
    //move the robot forward in all the speeds
    my_bot.move_forward(1);
    delay(1000);
    my_bot.move_forward(2);
    delay(1000);
    my_bot.move_forward(3);
    delay(1000);
    my_bot.move_forward(4);
    delay(1000);
    //turn the robot right in all the speeds
    my_bot.turn_right(1);
    delay(1000);
    my_bot.turn_right(2);
    delay(1000);
    my_bot.turn_right(3);
    delay(1000);
    my_bot.turn_right(4);
    delay(1000);
    //turn the robot left in all the speeds
    my_bot.turn_left(1);
    delay(1000);
    my_bot.turn_left(2);
    delay(1000);
    my_bot.turn_left(3);
    delay(1000);
    my_bot.turn_left(4);
    delay(1000);
    //move the robot back in all the speeds
    my_bot.move_back(1);
    delay(1000);
    my_bot.move_back(2);
    delay(1000);
    my_bot.move_back(3);
    delay(1000);
    my_bot.move_back(4);
    delay(1000);
}
