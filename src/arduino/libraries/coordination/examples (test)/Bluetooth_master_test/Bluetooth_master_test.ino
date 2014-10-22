/**
 * @file    Bluetooth_master_test.ino
 * @brief   test Bluetooth master mode
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
bool paired=false;
char d='0';
void setup()
{
    Serial.begin(38400);
}
void loop()
{  
    if(paired==false) //pairs with robot 2
    {
        paired=my_bot.bt.pair(2);
        delay(2000);
    }
    //sends '1' or '0' each second
    d='1';
    my_bot.bt.send_data(d);
    delay(1000);

    d='0';
    my_bot.bt.send_data(d);
    delay(1000);
}
