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
        MotorInterface();

        /**
         * @brief Destructor.
         */
        virtual ~MotorInterface();

        /**
         * @brief get_direction
         * @return
         */
        virtual int get_direction() = 0;

        /**
         * @brief set_direction
         * @param direction
         */
        virtual void set_direction(int direction) = 0;

        /**
         * @brief get_velocity
         * @return
         */
        virtual int get_velocity() = 0;

        /**
         * @brief set_velocity
         * @param velocity
         */
        virtual void set_velocity(int velocity) = 0;

    private:
        int _pwm_pin;
        int _direction;
        int _velocity;
};

#endif
