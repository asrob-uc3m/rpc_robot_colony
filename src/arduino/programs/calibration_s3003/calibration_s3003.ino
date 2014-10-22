#include <Servo.h>

Servo servoR;
Servo servoL;
int servoPinR = 9;
int servoPinL = 10;

void setup()
{
    pinMode(13,OUTPUT);
    servoR.attach(servoPinR);
    servoL.attach(servoPinL);
    Serial.begin(9600);
}

void loop()
{
    // Parada
    servoR.write(90);
    servoL.write(90);
    delay(2000);
    servoR.write(180);
    servoL.write(0);
    delay(2000);
    servoR.write(90);
    servoL.write(90);
    delay(2000);
    servoR.write(0);
    servoL.write(180);
    delay(2000);
}


