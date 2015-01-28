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
         * @param velocity Value between -100 and 100. Value 0 stop.
         * @return 0 if success and -1 if error.
         */
        int move(int velocity);

    private:
        Servo _servo;

        static const float MAX_VELOCITY = 180.0;
        static const float BASE_VELOCITY = 90.0;
        static const float MIN_VELOCITY = 0.0;
};

#endif
