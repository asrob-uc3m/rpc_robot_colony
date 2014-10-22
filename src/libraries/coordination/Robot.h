/**
 * @file    Robot.h
 * @brief   Robot class with movemment functions
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "Servomotor.h"
#include "UltrasonicSensor.h"
#include "Arduino.h"
#include  "Bluetooth.h"

class Robot
{ 
    public:

        /**
         * @brief Empty constructor
         * @param
         * @return
         */
        Robot();

        /**
          * @brief destructor
          * @param
          * @return
          */
        ~Robot();

        /**
          * @brief Robot constructor with default parameters
          * @param smr: pin number where right servomotor signal is wired
          * @param sml: pin number where left servomotor signal is wired
          * @param echor: pin number where right ultrasonic sensor echo is wired
          * @param echol: pin number where left ultrasonic sensor echo is wired
          * @param triggerr: pin number where right ultrasonic sensor trigger is wired
          * @param triggerl: pin number where left ultrasonic sensor trigger is wired
          * @param key: pin number where bluetooth module key pin is wired
          * @param power: pin number where bluetooth module power pin is wired
          * @return
          */
        Robot(int robot_ID,int smr,int sml,int echor=5,int echol=7,int triggerr=6,int triggerl=8, int key=3, int power=14);

        /**
          * @brief Copy constructor
          * @param rc: Robot object to copy
          * @return
          */
        Robot(const Robot &rc);

        /**
         * @brief get robot ID
         * @param
         * @return
         */
        int get_ID();

        /**
         * @brief Move the robot forward
         * @param speed: speed of the movemment-range [1,4]
         * @return
         */
        void move_forward(int speed);

        /**
         * @brief Move the robot back
         * @param speed: speed of the movemment-range [1,4]
         * @return
         */
        void move_back(int speed);

        /**
         * @brief turn the robot right
         * @param speed: speed of the movemment-range [1,4]
         * @return
         */
        void turn_right(int speed);

        /**
         * @brief turn the robot left
         * @param speed: speed of the movemment-range [1,4]
         * @return
         */
        void turn_left(int speed);

        /**
         * @brief stop the robot
         * @param speed: speed of the movemment-range [1,4]
         * @return
         */
        void stop_robot();

        UltrasonicSensor us_r;
        UltrasonicSensor us_l;

        Bluetooth bt;
    private:
        int _robot_ID;

        ServoMotor _sm_r;
        ServoMotor _sm_l;
};

#endif // ROBOT_H
