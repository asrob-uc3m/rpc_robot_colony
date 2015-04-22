#ifndef DISTANCESENSORINTERFACE_H
#define DISTANCESENSORINTERFACE_H

/**
 * @file        distance_sensor_interface.h
 * @brief       The Distance Sensor Interface class
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

class DistanceSensorInterface
{
    public:
        /**
         * @brief Parametrized constructor.
         */
        DistanceSensorInterface(int echo_pin, int triger_pin)
        {
            _echo_pin = echo_pin;
            _triger_pin = triger_pin;
        }

        /**
         * @brief Destructor.
         */
        virtual ~DistanceSensorInterface()
        {
        }

        /**
         * @brief get_distance
         * @return the value of the distance detected.
         */
        virtual float get_distance() const = 0;

    protected:
        int _echo_pin;
        int _triger_pin;
};

#endif
