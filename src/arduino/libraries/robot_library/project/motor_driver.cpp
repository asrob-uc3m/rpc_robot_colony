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

MotorDriver::MotorDriver(int pwm_pin, int dir_pin) : MotorInterface()
{
    _pwm_pin = pwm_pin;
    _dir_pin = dir_pin;

    pinMode(_pwm_pin, OUTPUT);
    pinMode(_dir_pin, OUTPUT);
}

//////////////////////////////////////////////////

MotorDriver::~MotorDriver()
{
}

//////////////////////////////////////////////////

void MotorDriver::move(int direction, int velocity)
{
    int total_vel = 0;
    int min_scale = 0;
    int max_scale = 100;

    // convert velocity (0-100 to 0-255)
    total_vel = ((MAX_VELOCITY - MIN_VELOCITY) * (velocity - min_scale)) / (max_scale - min_scale);

    // set direction (0- LOW, 1- HIGH)
    digitalWrite(_dir_pin, direction);

    // set velocity
    analogWrite(_pwm_pin, total_vel);
}

//////////////////////////////////////////////////
