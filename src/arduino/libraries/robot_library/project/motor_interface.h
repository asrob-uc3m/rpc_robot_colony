#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

/**
 * @file        motor_interface.h
 * @brief       The Motor Interface class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

class MotorInterface
{
    public:
        /**
         * @brief Parametrized constructor.
         */
        MotorInterface(int pwm_pin)
        {
            _pwm_pin = pwm_pin;
        }

        /**
         * @brief Destructor.
         */
        virtual ~MotorInterface()
        {
        }

        /**
         * @brief move
         * @param velocity Value between -100 and 100. Value 0 stop.
         * @return 0 if success and -1 if error.
         */
        virtual int move(int velocity) = 0;

    protected:
        int _pwm_pin;
};

#endif
