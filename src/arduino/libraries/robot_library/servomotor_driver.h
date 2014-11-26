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

#include <motor_interface.h>
#include <Arduino.h>
#include <Servo.h>

class ServomotorDriver : public MotorInterface
{
    public:
        /**
         * @brief Constructor.
         */
        ServomotorDriver();

        /**
         * @brief Destructor.
         */
        ~ServomotorDriver();

        /**
         * @brief get_direction
         * @return
         */
        int get_direction();

        /**
         * @brief set_direction
         * @param direction
         */
        void set_direction(int direction);

        /**
         * @brief get_velocity
         * @return
         */
        int get_velocity();

        /**
         * @brief set_velocity
         * @param velocity
         */
        void set_velocity(int velocity);
};

#endif
