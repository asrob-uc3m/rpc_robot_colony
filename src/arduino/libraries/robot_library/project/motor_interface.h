#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

/**
 * @file        motor_interface.h
 * @brief       The Motor Interface class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-11
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

class MotorInterface
{
    public:
        /**
         * @brief Constructor.
         */
        MotorInterface() {}

        /**
         * @brief Destructor.
         */
        virtual ~MotorInterface() {}

        /**
         * @brief move
         * @param direction Value 0 or 1.
         * @param velocity Value between 0 and 100.
         * @return
         */
        virtual void move(int direction, int velocity) {
        }
};

#endif
