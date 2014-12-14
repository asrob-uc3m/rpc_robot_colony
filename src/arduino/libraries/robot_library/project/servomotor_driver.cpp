/**
 * @file        servomotor_driver.cpp
 * @brief       The Servomotor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-12
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "servomotor_driver.h"

//////////////////////////////////////////////////

ServomotorDriver::ServomotorDriver(int pwm_pin) : MotorInterface()
{
    _servo.attach(pwm_pin);
}

//////////////////////////////////////////////////

ServomotorDriver::~ServomotorDriver()
{
    _servo.detach();
}

//////////////////////////////////////////////////

void ServomotorDriver::move(int direction, int velocity)
{
    int total_vel = 0;
    int min_scale = 0;
    int max_scale = 100;

    //TODO: change direction to an enum
    switch (direction) {
        case 0:
            // convert velocity (0-100 to 90-0)
            total_vel = ((MIN_VELOCITY - BASE_VELOCITY) * (velocity - min_scale)) / (max_scale - min_scale);
            break;
        case 1:
            // convert velocity (0-100 to 90-180)
            total_vel = ((MAX_VELOCITY - BASE_VELOCITY) * (velocity - min_scale)) / (max_scale - min_scale);
            break;
        default:
            break;
    }

    // set servo velocity
    Serial.println(total_vel);
    _servo.write(total_vel);
}

//////////////////////////////////////////////////
