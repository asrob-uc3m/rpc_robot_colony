#ifndef HCSR04_WRAPPER_H
#define HCSR04_WRAPPER_H

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

#include <Arduino.h>
#include "distance_sensor_interface.h"
#include "HCSR04Ultrasonic"

class Hcsr04Wrapper : public DistanceSensorInterface
{
    public:
        /**
         * @brief Parametrized constructor.
         */
        Hcsr04Wrapper(int echo_pin, int triger_pin)
        {
            _echo_pin = echo_pin;
            _triger_pin = triger_pin;
        }

        /**
         * @brief Destructor.
         */
        ~Hcsr04Wrapper()
        {
        }

        /**
         * @brief get_distance
         * @return the value of the distance detected.
         */
        float get_distance() const;
};

#endif
