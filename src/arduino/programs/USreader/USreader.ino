// variables globales
int sigPinR = 6;
int sigPinL = 5;
float soundSpeed = 343.2;

//
//  measureUS()
//  Devuelve la distancia al obstaculo mas cercano en cm
//
float measureUS(int sigPin)
{
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

void setup()
{
    Serial.begin(9600);    // abrir el puerto serie con una velocidad de 9600 baudios
    Serial.flush();        // vaciar el puerto serie
}

void loop()
{
    float distL, distR;
    distL = measureUS(sigPinL);
    distR = measureUS(sigPinR);

    Serial.print(distL);
    Serial.print("    ");
    Serial.println(distR);
}


