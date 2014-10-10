// Este sketch lee números enteros eviados por el puerto serie
// y varía la frequencia de parpadeo de un LED dependiendo de su valor.

char buffer[10];  //array para almacenar el mensaje recibido
int x=0;          //tiempo ON/OFF (entero)
int ledPin=13;    //LED connectado al pin 13

void setup(){
    Serial.begin(9600);    //abrir el puerto serie con una velocidad de 9600 baudios
    Serial.flush();        //Vaciar el puerto serie
    pinMode(ledPin, OUTPUT);  //configurar el pin del LED como SALIDA
}

void loop(){
    if (Serial.available() > 0){    //Si hay algo en el puerto serie
        x=readInt();                  //leer y almacenar en la variable x
        Serial.print("ON/OFF cada: ");  //escribir mensaje sobre la info recibida
        Serial.print(x);
        Serial.println(" ms");
    }

    digitalWrite(ledPin, HIGH);  //encender y apagar el LED
    delay(x);
    digitalWrite(ledPin, LOW);
    delay(x);
}

int readInt(){
    int index=0;  //indica la posicin en el array de chars
    delay(10);    //esperar a que llegue todo el mensaje
    int numChar=Serial.available();  //numero de bytes entrantes

    while(numChar--){  //guardar cada byte en una posicin del array
        buffer[index++]=Serial.read();
    }

    int number=atoi(buffer);  //convertir los caracteres a un numero entero

    for (int i=0; i<10; i++){  //escribir NULL en todas las posiciones del array
        buffer[i]='\0';
    }
    Serial.flush();  //vaciar el puerto serie para que no haya nada

    return number;
}


