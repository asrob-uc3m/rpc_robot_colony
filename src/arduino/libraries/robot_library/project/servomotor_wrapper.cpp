/**
 * @file        servomotor_driver.cpp
 * @brief       The Servomotor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "servomotor_wrapper.h"

//////////////////////////////////////////////////

ServomotorWrapper::ServomotorWrapper(int pwm_pin) : MotorInterface(pwm_pin)
{
    _servo.attach(pwm_pin);
}

//////////////////////////////////////////////////

ServomotorWrapper::~ServomotorWrapper()
{
    _servo.detach();
}

//////////////////////////////////////////////////

int ServomotorWrapper::move(int velocity)
{
    int total_vel = 0;
    int min_scale = 0, max_scale = 100;

    // check correct limits
    if (velocity < -max_scale || velocity > max_scale) {
        return -1;
    }

    if (velocity < 0) {
        // convert velocity (0-100 to 90-0)
        total_vel = ((MIN_VELOCITY - BASE_VELOCITY) / (max_scale - min_scale)) * abs(velocity) + BASE_VELOCITY;
        Serial.println("entra 90-0");
        Serial.println(((MIN_VELOCITY - BASE_VELOCITY) / (max_scale - min_scale)) * velocity + BASE_VELOCITY);
    }
    else if (velocity >= 0) {
        // convert velocity (0-100 to 90-180)
        total_vel = ((MAX_VELOCITY - BASE_VELOCITY) / (max_scale - min_scale)) * velocity + BASE_VELOCITY;
        Serial.println("entra 90-180");
        Serial.println(((MAX_VELOCITY - BASE_VELOCITY) / (max_scale - min_scale)) * velocity + BASE_VELOCITY);
    }

    // set servo velocity
    _servo.write(total_vel);

    Serial.print("velocity: ");
    Serial.print(velocity);
    Serial.print("\ttotal_vel: ");
    Serial.println(total_vel);

    return 0;
}

//////////////////////////////////////////////////
