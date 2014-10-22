/**
 * @file    Bluetooth.h
 * @brief   Bluetooth class for master and slaves modules
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#ifndef BT_H
#define BT_H

#include "Arduino.h"

class Bluetooth
{
    public:

        /**
         * @brief Empty constructor
         * @param
         * @return
         */
        Bluetooth();

        /**
         * @brief constructor
         * @param key_p: pin number where bluetooth module key pin is wired
         * @param power_p: pin number where bluetooth module power pin is wired
         * @return
         */
        Bluetooth(int key_p,int power_p);

        /**
         * @brief reset the bluetooth module
         * @param
         * @return
         */
        void bt_reset();

        /**
         * @brief pair the master module with the specified slave module
         * @param robot_to_pair: the number of the slave module to pair the master
         * @return
         */
        bool pair(int robot_to_pair);

        /**
         * @brief set the module in slave mode and conectivity mode to be connected with the master
         * @param
         * @return
         */
        void hear();

        /**
         * @brief the master module send the specified character
         * @param data: the character to send
         * @return
         */
        void send_data(char data);

        /**
         * @brief set the bluetooth mode; AT mode or conectivity mode
         * @param at_mode: if 1 sets AT mode, if 0 sets conectivity mode
         * @return
         */
        void select_at_mode(bool at_mode);

        int power;
        int key;
};

#endif
