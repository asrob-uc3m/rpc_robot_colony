/**
 * @file    UltrasonicSensor.h
 * @brief   UltrasonicSensor class with getting distance function
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#ifndef US_H
#define US_H

#include <Ultrasonic.h>
#include "Arduino.h"

class UltrasonicSensor
{
    public:
        /**
         * @brief Empty constructor
         * @param
         * @return
         */
        UltrasonicSensor();

        /**
         * @brief constructor
         * @param echo_pin: Ultrasonic sensor echo pin
         * @param trigger_pin: Ultrasonic sensor trigger pin
         * @return
         */
        UltrasonicSensor(int echo_pin,int trigger_pin);

        /**
       * @brief Copy constructor
       * @param UltrasonicSensor object to copy
       * @return
       */
        UltrasonicSensor(const UltrasonicSensor & us);

        /**
       * @brief get echo pin
       * @param
       * @return _echo_pin
       */
        int get_echo();

        /**
         * @brief get trigger pin
         * @param
         * @return _trigger_pin
         */
        int get_trigger();

        /**
         * @brief set echo pin
         * @param echo_pin: value to asign to _echo_pin
         * @return
         */
        void set_echo(int echo_pin);

        /**
         * @brief set trigger pin
         * @param trigger_pin: value to asign to _trigger_pin
         * @return
         */
        void set_trigger(int trigger_pin);

        /**
         * @brief get obstacles distance
         * @param
         * @return distance value as float
         */
        float get_distance();

    private:
        int _echo_pin;
        int _trigger_pin;

};

#endif //US_H
