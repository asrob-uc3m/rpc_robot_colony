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

    //TODO: change direction to an enum
    switch (direction) {
        case 0:
            // convert velocity (0-100 to 90-0)
            total_vel = ((100 - velocity) * BASE_VELOCITY) / 100;
            break;
        case 1:
            // convert velocity (0-100 to 90-180)
            total_vel = ((velocity - MIN_VELOCITY) * 100) / (BASE_VELOCITY - MIN_VELOCITY);
            break;
        default:
            break;
    }

    // set servo velocity
    Serial.println(total_vel);
    _servo.write(total_vel);
}

//////////////////////////////////////////////////
