void setup(){
    Serial.begin(9600);
    Serial.flush();
}

void loop(){
    if (Serial.available()>0){
        while(Serial.available()!=0){
            Serial.print(byte(Serial.read()));
        }
    }
}

