/**
 * @file    ServoMotor.cpp
 * @brief   Servomotor class
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */
#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "Arduino.h"
#include <Servo.h>

class ServoMotor
{
    public:
        /**
         * @brief Empty constructor
         * @param
         * @return
         */
        ServoMotor();

        /**
         * @brief constructor
         * @param sm_pin: Servomotor pin
         * @return
         */
        ServoMotor(int sm_pin);

        /**
         * @brief copy constructor
         * @param SMotor: ServoMotor object to copy
         * @return
         */
        ServoMotor(const ServoMotor & SMotor);

        /**
         * @brief get servomotor pin
         * @param
         * @return _sm_pin
         */
        int get_pin();

        /**
         * @brief set servomotor pin
         * @param sm_pin: pin value to asign to _sm_pin
         * @return
         */
        void set_pin(int sm_pin);

        Servo my_servo; //! Arduino Servo.h library
    private:
        int _sm_pin;
};

#endif // SERVOMOTOR_H
