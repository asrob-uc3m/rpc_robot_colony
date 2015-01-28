/**
 * @file        hcsr04_wrapper.h
 * @brief       The HCSR04 Wrapper class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "hcsr04_wrapper.h"

//////////////////////////////////////////////////

Hcsr04Wrapper::Hcsr04Wrapper(int echo_pin, int triger_pin) : DistanceSensorInterface(echo_pin, triger_pin)
{
    pinMode(pwm_pin, OUTPUT);
    pinMode(_dir_pin, OUTPUT);
}

//////////////////////////////////////////////////

Hcsr04Wrapper::~Hcsr04Wrapper()
{
}

//////////////////////////////////////////////////

float Hcsr04Wrapper::get_distance()
{

}

//////////////////////////////////////////////////

