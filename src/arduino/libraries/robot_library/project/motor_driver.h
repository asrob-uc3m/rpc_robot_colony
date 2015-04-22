#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

/**
 * @file        motor_driver.h
 * @brief       The Motor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include <Arduino.h>
#include "motor_interface.h"

class MotorDriver : public MotorInterface
{
    public:
        /**
         * @brief Constructor.
         */
        MotorDriver(int pwm_pin, int dir_pin);

        /**
         * @brief Destructor.
         */
        ~MotorDriver();

        /**
         * @brief move
         * @param velocity Value between -100 and 100. Value 0 stop.
         * @return 0 if success and -1 if error.
         */
        int move(int velocity);

    private:
        int _dir_pin;

        static const float MAX_VELOCITY = 255.0;
        static const float MIN_VELOCITY = 0.0;
};

#endif
