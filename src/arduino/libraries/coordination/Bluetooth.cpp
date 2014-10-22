/**
 * @file    Bluetooth.h
 * @brief   Bluetooth class for master and slaves modules
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#include "Bluetooth.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
Bluetooth::Bluetooth()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Bluetooth::Bluetooth( int key_p, int power_p=14)//when slave is out of range
{
    power=power_p;
    key=key_p;

    /*!
       Initialize set bluetooth pin as LOW
    */
    pinMode(power, OUTPUT);
    pinMode(key, OUTPUT);
    digitalWrite(power, LOW);
    digitalWrite(key, LOW);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bluetooth::bt_reset()
{
    Serial.flush();
    delay(500);

    /*!
       Reset the bluetooth device using the power
    */
    digitalWrite(power, LOW);
    delay(1000);
    digitalWrite(power, HIGH);
    delay(500);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Bluetooth::pair(int robot_to_pair)
{
    bool paired=false;

    Serial.begin(38400);
    select_at_mode(1);

    delay(1000);
    Serial.println("AT+ROLE=1");
    delay(1000);
    Serial.println("AT+INIT");
    delay(2000);

    switch (robot_to_pair) {

        case 1: //m_1

            break;

        case 2: //m_2
            Serial.println("AT+PAIR=2013,12,129042,40");
            delay(4000);
            Serial.println("AT+LINK=2013,12,129042");
            delay(3000);

            break;

        case 3://s_1
            Serial.println("AT+PAIR=2013,6,201007,40");
            delay(3000);
            Serial.println("AT+LINK=2013,6,201007");
            delay(3000);

            break;

        case 4://s_3
            Serial.println("AT+PAIR=2013,6,200284,40");
            delay(3000);
            Serial.println("AT+LINK=2013,6,200284");
            delay(3000);

            break;
        case 5://s_2

            Serial.println("AT+PAIR=2013,6,201008,40");
            delay(3000);
            Serial.println("AT+LINK=2013,6,201008");
            delay(3000);

            break;
        default:
            break;
    }
    paired=true;
    return paired;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bluetooth::hear()
{
    Serial.begin(38400);
    select_at_mode(1);
    delay(1000);
    Serial.println("AT+ROLE=0");
    delay(1000);
    select_at_mode(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bluetooth::select_at_mode(bool at_mode=1)
{
    digitalWrite(key, (1 == at_mode)?HIGH:LOW);
    bt_reset();
    Serial.begin(38400);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bluetooth::send_data(char data)
{
    Serial.println((String)data);
}

