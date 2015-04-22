/**
 * @file        test_servomotors.cpp
 * @brief       Main.
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "../servomotor_wrapper.h"

MotorInterface *servo = new ServomotorWrapper(9);

void setup()
{
    Serial.begin(9600);
    Serial.flush();
}

void loop()
{
    // move servomotor

    // stop
    servo->move(0);
    delay(2000);

    // move fast back
    servo->move(100);
    delay(2000);

    // stop
    servo->move(0);
    delay(2000);

    // move fast front
    servo->move(-100);
    delay(2000);
}
