/**
 * @file    Bluetooth_slave_test.ino
 * @brief   test Bluetooth slave mode
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

Robot my_bot(3,10,9,3,4);
char d='0';

void setup()
{
    Serial.begin(38400);
    pinMode(13,OUTPUT);
}
void loop()
{  
    if (Serial.available())//if data received
    {
        char tmpChar = Serial.read();
        switch(tmpChar)
        {
            case '0':
                digitalWrite(13,LOW); //switch off the LED
                break;
            case '1':
                digitalWrite(13,HIGH); //switch on the LED
                break;
        }
    }
}
