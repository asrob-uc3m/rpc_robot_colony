#ifndef SERVOMOTOR_DRIVER_H
#define SERVOMOTOR_DRIVER_H

/**
 * @file        servomotor_driver.h
 * @brief       The Servomotor Driver class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-11
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "Arduino.h"
#include "../../../../libraries/Servo/Servo.h"

#include "motor_interface.h"

#define MAX_VELOCITY    180
#define BASE_VELOCITY   90
#define MIN_VELOCITY    0

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
         * @param direction Value 0 or 1.
         * @param velocity Value between 0 and 100.
         * @return
         */
        void move(int direction, int velocity);

    private:
        Servo _servo;
};

#endif
