/////////////////////////////////////////////////
//////////  Sensores
/////////////////////////////////////////////////

//
//  measureUS()
//  Devuelve la distancia al obstaculo mas cercano en cm
//
float measureUS(int sigPin)
{
  float soundSpeed = 343.2;
  
  // Enviando el pulso
  pinMode(sigPin, OUTPUT);
  // Lo ponemos a 0
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  // Subimos a 1
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  // Terminamos el pulso
  digitalWrite(sigPin, LOW);
  // Pulso enviado

  // Leemos la duracion del pulso
  pinMode(sigPin, INPUT);
  unsigned long duration = pulseIn(sigPin,HIGH); // In use

  // Convertimos este tiempo en distancia (centimetros)
  return (duration/10000.0) * soundSpeed / 2.0;
}

