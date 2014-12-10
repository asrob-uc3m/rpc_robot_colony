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

    switch (direction) {
        case 0:
            total_vel = ((100 - velocity) * BASE_VELOCITY) / 100;
            _servo.write(total_vel);
            break;
        case 1:
            total_vel = ((velocity - MIN_VELOCITY) * 100) / (BASE_VELOCITY - MIN_VELOCITY);
            _servo.write(velocity);
            break;
        default:
            break;
    }
}

//////////////////////////////////////////////////
