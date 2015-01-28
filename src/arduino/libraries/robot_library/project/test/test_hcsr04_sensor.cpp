/**
 * @file        test_hcsr04_sensor.cpp
 * @brief       Main.
 *
 * @author      Raul Perula-Martinez <raul.perula@uc3m.es>
 * @date        2015-01
 *
 * @version     1.0.0
 * @license     GPLv3
 * @copyright   Asociacion de Robotica, University Carlos III of Madrid
 */

#include "../hcsr04_driver.h"

DistanceSensorInterface *sensor = new Hcsr04Driver(2, 3);

void setup()
{
    Serial.begin(9600);
    Serial.flush();
}

void loop()
{
    // show distance
    float distance = sensor->get_distance();

    Serial.print("Distance (cm): ");
    Serial.println(distance);
}

