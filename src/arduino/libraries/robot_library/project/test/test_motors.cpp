/**
 * @file        test_motors.cpp
 * @brief       Main.
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-12
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "../servomotor_driver.h"
#include "../motor_driver.h"

ServomotorDriver servo(9);
MotorDriver motor(4, 5);

void setup()
{

}

void loop()
{
    // move servomotor
    // direction 0, velocity 0
    servo.move(0, 0);
    delay(2000);
    // direction 0, velocity 100
    servo.move(0, 100);
    delay(2000);
    // direction 1, velocity 0
    servo.move(1, 0);
    delay(1000);
    // direction 1, velocity 100
    servo.move(1, 100);
    delay(1000);

    // direction 1, velocity 0
    servo.move(1, 0);
    delay(1000);

    delay(1000);

    // move continuous motor
    // direction 0, velocity 0
//    motor.move(0, 0);
//    // direction 0, velocity 50
//    motor.move(0, 50);
//    // direction 0, velocity 100
//    motor.move(0, 100);
//    // direction 1, velocity 0
//    motor.move(1, 0);
//    // direction 1, velocity 50
//    motor.move(1, 50);
//    // direction 1, velocity 100
//    motor.move(1, 100);
}
