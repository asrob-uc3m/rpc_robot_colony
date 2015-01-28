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

class Hcsr04Driver : public DistanceSensorInterface
{
    public:
        /**
         * @brief Parametrized constructor.
         */
        Hcsr04Driver(int echo_pin, int triger_pin);

        /**
         * @brief Destructor.
         */
        ~Hcsr04Driver();

        /**
         * @brief get_distance
         * @return the value of the distance detected.
         */
        float get_distance() const;
};

#endif
