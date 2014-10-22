/**
 * @file    Get_obstacle_distance.ino
 * @brief   Ultrasonic Sensors test
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
float distr;
float distl;
void setup()
{
  Serial.begin(38400);
}
void loop()
{  
  distr= my_bot.us_r.get_distance(); //get right Ultrasonic Sensor read distance
  distl= my_bot.us_l.get_distance(); //get left Ultrasonic Sensor read distance
  Serial.println(distr);
  Serial.println(distl);
}
