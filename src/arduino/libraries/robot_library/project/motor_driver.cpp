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

    // convert velocity (0-100 to 0-255)
    total_vel = ((velocity - MIN_VELOCITY) * 255) / (100 - MIN_VELOCITY);

    // set direction (0- LOW, 1- HIGH)
    digitalWrite(_dir_pin, direction);

    // set velocity
    analogWrite(_pwm_pin, total_vel);
}

//////////////////////////////////////////////////
