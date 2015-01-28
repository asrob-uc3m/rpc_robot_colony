/**
 * @file        motor_driver.cpp
 * @brief       The Motor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-12
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "motor_driver.h"

//////////////////////////////////////////////////

MotorDriver::MotorDriver(int pwm_pin, int dir_pin) : MotorInterface(pwm_pin)
{
    _dir_pin = dir_pin;

    pinMode(pwm_pin, OUTPUT);
    pinMode(_dir_pin, OUTPUT);
}

//////////////////////////////////////////////////

MotorDriver::~MotorDriver()
{
}

//////////////////////////////////////////////////

int MotorDriver::move(int velocity)
{
    int total_vel = 0;
    int min_scale = 0, max_scale = 100;
    int direction;

    // check correct limits
    if (velocity < -max_scale || velocity > max_scale) {
        return -1;
    }

    // convert velocity (0-100 to 0-255)
    total_vel = ((MAX_VELOCITY - MIN_VELOCITY) * (abs(velocity) - min_scale)) / (max_scale - min_scale);

    // set direction (0- LOW, 1- HIGH)
    if (velocity < 0) {
        direction = LOW;
    }
    else if (velocity >= 0) {
        direction = HIGH;
    }
    digitalWrite(_dir_pin, direction);

    // set velocity
    analogWrite(_pwm_pin, total_vel);

    Serial.print("velocity: ");
    Serial.print(velocity);
    Serial.print("\ttotal_vel: ");
    Serial.println(total_vel);

    return 0;
}

//////////////////////////////////////////////////
