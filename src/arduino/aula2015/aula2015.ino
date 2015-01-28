#include <Servo.h> 

// Hay que sustituir el numero por el numero del robot que os haya tocado sin las comillas.
// Ejemplo: 
// int ROBOT = 4;
int ROBOT = 4;
 
void loop() 
{ 
  continua_recto(2);
  giro_derecha(2);
  giro_izquierda(2);
  hacia_atras(2);
  parar(10);
} 
