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

#include "../motor_driver.h"

MotorDriver motor(4, 5);

void setup()
{

}

void loop()
{
    // move continuous motor
    // direction 0, velocity 0 (stop)
    motor.move(0, 0);
    delay(2000);
    // direction 0, velocity 100 (move fast back)
    motor.move(0, 100);
    delay(2000);
    // direction 1, velocity 0 (stop)
    motor.move(1, 0);
    delay(1000);
    // direction 1, velocity 100 (move fast front)
    motor.move(1, 100);
    delay(1000);

    // direction 1, velocity 0 (stop)
    motor.move(1, 0);
    delay(1000);

    delay(1000);
}
