#ifndef SERVOMOTOR_DRIVER_H
#define SERVOMOTOR_DRIVER_H

/**
 * @file        servomotor_driver.h
 * @brief       The Servomotor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-12
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include <Arduino.h>
#include "Servo/Servo.h"

#include "motor_interface.h"

class ServomotorDriver : public MotorInterface
{
    public:
        /**
         * @brief Constructor.
         */
        ServomotorDriver(int pwm_pin);

        /**
         * @brief Destructor.
         */
        ~ServomotorDriver();

        /**
         * @brief move
         * @param velocity Value between -100 and 100.
         * @return 0- success, -1- error.
         */
        int move(int velocity);

    private:
        Servo _servo;

        static const int MAX_VELOCITY = 180;
        static const int BASE_VELOCITY = 90;
        static const int MIN_VELOCITY = 0;
};

#endif
