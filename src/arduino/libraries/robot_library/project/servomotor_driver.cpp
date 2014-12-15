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

ServomotorDriver::ServomotorDriver(int pwm_pin) : MotorInterface(pwm_pin)
{
    _servo.attach(pwm_pin);
}

//////////////////////////////////////////////////

ServomotorDriver::~ServomotorDriver()
{
    _servo.detach();
}

//////////////////////////////////////////////////

int ServomotorDriver::move(int velocity)
{
    int total_vel = 0;
    int min_scale = 0, max_scale = 100;

    // check correct limits
    if (velocity < -100 || velocity > 100) {
        return -1;
    }

    if (velocity < 0) {
        // convert velocity (0-100 to 90-0)
        total_vel = ((MIN_VELOCITY - BASE_VELOCITY) * (abs(velocity) - min_scale)) / (max_scale - min_scale);
    }
    else if (velocity >= 0) {
        // convert velocity (0-100 to 90-180)
        total_vel = ((MAX_VELOCITY - BASE_VELOCITY) * (velocity - min_scale)) / (max_scale - min_scale);
    }

    // set servo velocity
    _servo.write(total_vel);

    return 0;
}

//////////////////////////////////////////////////
