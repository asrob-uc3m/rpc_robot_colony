/**
 * @file        robot_library.cpp
 * @brief       Main.
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2014-11
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "Arduino.h"

int i = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(i);

    i++;
}
