/**
 * @file        test_motors.cpp
 * @brief       Main.
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "../motor_driver.h"

MotorInterface *motor = new MotorDriver(4, 5);

void setup()
{
    Serial.begin(9600);
    Serial.flush();
}

void loop()
{
    // move continuous motor

    // stop
    motor->move(0);
    delay(2000);

    // move fast back
    motor->move(100);
    delay(2000);

    // stop
    motor->move(0);
    delay(2000);

    // move fast front
    motor->move(-100);
    delay(2000);
}
