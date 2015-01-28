/**
 * @file        hcsr04_wrapper.cpp
 * @brief       The HCSR04 Wrapper class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "hcsr04_driver.h"

//////////////////////////////////////////////////

Hcsr04Driver::Hcsr04Driver(int echo_pin, int triger_pin) : DistanceSensorInterface(echo_pin, triger_pin)
{
    pinMode(_echo_pin, INPUT);
    pinMode(_triger_pin, OUTPUT);
}

//////////////////////////////////////////////////

Hcsr04Driver::~Hcsr04Driver()
{
}

//////////////////////////////////////////////////

float Hcsr04Driver::get_distance() const
{
    // set the pulse
    digitalWrite(_triger_pin, LOW);
    delayMicroseconds(2);

    digitalWrite(_triger_pin, HIGH);
    delayMicroseconds(10);

    digitalWrite(_triger_pin, LOW);

    // calc the pulse time
    long microsec = pulseIn(_echo_pin, HIGH);

    // calc the distance
    float distance = microsec / 27.6233 / 2.0;

    return distance;
}

//////////////////////////////////////////////////

