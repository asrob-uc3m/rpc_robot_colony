/////////////////////////////////////////////////
//////////  Main
/////////////////////////////////////////////////

#include <Servo.h>

// variables globales

Servo servoR;
Servo servoL;
int sigPinR = 5;      // pin sensor US derecho
int sigPinL = 6;      // pin sensor US izquierdo
int servoPinR = 9;    // pin motor derecho
int servoPinL = 10;   // pin motor izquierdo
int pinRedLed = 11;   // pin red led
int pinYelLed = 12;   // pin yellow led
int pinGrnLed = 13;   // pin green led

int distR, distL = 0;
int flag = 0;
int i = 0;

/////////////////////////////////////////////////
//////////  Configuracion
/////////////////////////////////////////////////

void setup()
{
  Serial.begin(9600); // abrir el puerto serie con una velocidad de 9600 baudios
  servoR.attach(servoPinR);
  servoL.attach(servoPinL);
  Serial.flush();    // vaciar el puerto serie
  
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinYelLed, OUTPUT);
  pinMode(pinGrnLed, OUTPUT);
}

/////////////////////////////////////////////////
//////////  Bucle principal
/////////////////////////////////////////////////

void loop()
{
  distR = measureUS(sigPinR);
  distL = measureUS(sigPinL);
  Serial.print("distR: ");
  Serial.print(distR);
  Serial.print("    distL: ");
  Serial.println(distL);
  
  // AVANZAR: si las distancias de ambos sensores es mayor a 10 cm
  if(distR > 10 && distL > 10) {
    advance();
    digitalWrite(pinGrnLed, HIGH);
    if(flag == 0) {
      digitalWrite(pinYelLed, HIGH);
      flag = 1;
    }
    else {
      digitalWrite(pinYelLed, LOW);
      flag = 0;
    }
    digitalWrite(pinRedLed, LOW);
  }
  // PARADA
  else if(distR < 5 && distL < 5) {
    halt();
    digitalWrite(pinGrnLed, LOW);
    digitalWrite(pinYelLed, LOW);
    digitalWrite(pinRedLed, HIGH);
  }
  // GIRAR DER: si la distancia del sensor der. es mayor a la del sensor izq.
  else if(distR > distL) {
    turnR();
  }
  // GIRAR IZQ: si la distancia del sensor izq. es mayor a la del sensor der.
  else if(distR < distL) {
    turnL();
  }
}

