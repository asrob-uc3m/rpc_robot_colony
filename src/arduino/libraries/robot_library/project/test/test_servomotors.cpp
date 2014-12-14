/**
 * @file        test_servomotors.cpp
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

ServomotorDriver servo(9);

void setup()
{

}

void loop()
{
    // move servomotor
    // direction 0, velocity 0 (stop)
    servo.move(0, 0);
    delay(2000);
    // direction 0, velocity 100 (move fast back)
    servo.move(0, 100);
    delay(2000);
    // direction 1, velocity 0 (stop)
    servo.move(1, 0);
    delay(1000);
    // direction 1, velocity 100 (move fast front)
    servo.move(1, 100);
    delay(1000);

    // direction 1, velocity 0 (stop)
    servo.move(1, 0);
    delay(1000);

    delay(1000);
}
