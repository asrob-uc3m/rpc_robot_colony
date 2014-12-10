#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

/**
 * @file        motor_driver.h
 * @brief       The Motor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-11
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "Arduino.h"
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
         * @param direction Value 0 or 1.
         * @param velocity Value between 0 and 100.
         * @return
         */
        void move(int direction, int velocity);

    private:
        int _pwm_pin;
        int _dir_pin;

        static const int MAX_VELOCITY = 255;
        static const int MIN_VELOCITY = 0;
};

#endif
