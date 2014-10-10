// Sketch to control a differential drive robot (modified servos)

#include <Servo.h>

const int xx=90;  //Equilibrium point (servos do not turn)
int diff=0;  //Amount added or substracted to the equilibrium position
//depending on sign the servos go forwards or backwards
//depending the magnitude they turn faster or slower
//max speed corresponds to about dif=|10|
int t=0;

int rightServoPin=10;  //pins that the servos are attached to
int leftServoPin=11;

Servo rightServo;  //instance the servos
Servo leftServo;

char buffer[0];

void setup(){
    Serial.begin(9600);
    Serial.flush();
    rightServo.attach(rightServoPin);
    leftServo.attach(leftServoPin);
    writeStop(3000);  //start still
}

void loop(){
    if (Serial.available() > 0){
        delay(10);
        buffer[0]=Serial.read();

        switch (getDirVal(buffer[0])){
        case 1:
            if (checkDiff()!=0){ 
                diff++;
            }
            writeStraight(diff);
            break;
        case 2:
            if (checkDiff()!=1){ 
                diff--;
            }
            writeStraight(diff);
            break;
        case 3:
            t++;
            writeTurn(t);        
            break;
        case 4:
            t--;
            writeTurn(t);
            break;
        case 5:
            writeStop(10);
            diff=0;
        }
    }
}

void writeStop(int a){  //stops the robot, pass how long it must stop
    rightServo.write(xx);
    leftServo.write(xx);
    //Serial.println("Stopped");
    delay (a);
}

void writeStraight(int a){
    rightServo.write(xx-a);
    leftServo.write(xx+a);
    //Serial.println("Straight");
}

void writeTR (int a){
    rightServo.write(xx-diff+a);
    leftServo.write(xx+diff);
    //Serial.println("Turn Right");
}

void writeTL (int a){
    rightServo.write(xx-diff);
    leftServo.write(xx+diff-a);
    //Serial.println("Turn Left");
}

void writeTurn(int a){
    rightServo.write(xx-diff+a);
    leftServo.write(xx+diff+a);
}

int getDirVal(char a){
    a=buffer[0];
    int b;

    if (a=='w'){
        b=1;
    }
    else if (a=='s'){
        b=2;
    } 
    else if (a=='d'){
        b=3;
    }
    else if (a=='a'){
        b=4;
    }
    else if (a=='q'){
        b=5;
    }

    return b;
}

int checkDiff(){
    if (diff>=10){
        diff=10;
        return 0;
    }
    else if (diff<=-10){
        diff=-10;
        return 1;
    }
    else return 2;
}


