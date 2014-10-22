/**
 * @file    labyrinth master.ino
 * @brief   Robot master resolves labyrinth at guided or free mode and sends
 *          the information to the slaves robots by Bluetooth
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#include <Bluetooth.h>
#include <Robot.h>
#include <Servomotor.h>
#include <UltrasonicSensor.h>
#include <Ultrasonic.h>
#include <Servo.h>

#define NUMBER_OF_ROBOTS 4

float distr;
float distl;
int move=0;
int aux=6;
int cycle=0;
int i=0;
char d='0';
bool equal=false;
int *buffer = (int*)malloc(10*sizeof(int));
int buffer_size=0;
int buffer_limit=10;
char tmpChar='1';
bool end_pos=false;
bool paired=false;

Robot my_bot(1,10,9,5,7,6,8,3,4); //robot constructor

void setup()
{
    Serial.begin(38400);
    my_bot.bt.hear();//sets master module to slave role
}
void loop()
{
    if (Serial.available())//if data received
    {
        tmpChar = Serial.read();
    }
    if(tmpChar=='s')// avoid obstacles to resolve labyrinth
    {
        distr= my_bot.us_r.get_distance();
        distl= my_bot.us_l.get_distance();
        
        if(distr<15||distl<15)
        {
            if(distr<8||distl<8)
            {
                if((distr<4)||(distl<4))
                {
                    my_bot.move_back(2);//move the robot back-speed 2
                    delay(100);
                    move=1;
                }
                else
                {
                    if(distr<distl)
                    {
                        my_bot.turn_left(4);//turn the robot left-speed 4
                        delay(100);
                        move=2;
                    }
                    else
                    {
                        my_bot.turn_right(4);//turn the robot right-speed 4
                        delay(100);
                        move=3;
                    }
                }
            }
            else
            {
                if(distr <distl)
                {
                    my_bot.turn_left(2);//turn the robot left-speed 2
                    delay(100);
                    move=4;
                }
                else
                {
                    my_bot.turn_right(2);//turn the robot right-speed 2
                    delay(100);
                    move=5;
                }
            }
        }
        else
        {
            my_bot.move_forward(4);//move the robot forward-speed 2*
            move=6;
            buffer_manager();//save the information into a buffer
        }
    }
    else if (tmpChar=='0')//stop resolving the labyrinth and start the communication with the other robots
    {
        if(end_pos==false)//set the robot in its final position
        {
            my_bot.move_forward(4);
            delay(2000);
            end_pos=true;
        }
        my_bot.stop_robot();//stop the robot
        delay(500);

        if(equal)//when last movemment hasn't change
        {
            buffer_size=buffer_size+2;
        }

        if (paired==false)//when it hasn't pair with any device
        {
            for (int n=2; n<NUMBER_OF_ROBOTS; n++)
            {
                paired=my_bot.bt.pair(n);
                delay(2000);
                send_buffer(n);
                my_bot.bt.bt_reset();
            }
        }
    }
    else if((tmpChar=='1')||(tmpChar=='4')||(tmpChar=='5')||(tmpChar=='6'))//When robot master is be guided
    {
        switch(tmpChar)
        {
            case '1':  my_bot.move_back(2);//move the robot back-speed 2
                move=1;
                break;
            case '4':
                my_bot.turn_left(2);//turn the robot left-speed 2
                move=4;
                break;
            case '5':
                my_bot.turn_right(2);//turn the robot right-speed 2
                move=5;
                break;
            case '6':
                my_bot.move_forward(4);//move the robot forward-speed 4
                move=6;
                break;
        }
        delay(100);
        buffer_manager();//save information into a buffer
    }
}
void buffer_manager()
{
    if(aux==move)//when actual move is equal to the move before
    {
        buffer[i]=move; //collect actual move
        buffer[i+1]=cycle;//collect number of cycles
        cycle++;//increases cycles
        equal=true;
    }
    else
    {
        if(buffer_size==buffer_limit)
        {
            buffer = (int*) realloc (buffer, buffer_limit +25 * sizeof(int));//Makes the buffer bigger
            buffer_limit=buffer_limit +25;    //new buffer limit
        }
        buffer[i]=aux; //collect last move
        buffer[i+1]=cycle;//collect number of cycles
        cycle=0;//start cycles
        i=i+2;
        buffer_size=buffer_size+2;//new buffer size
        equal=false;
    }
    aux=move;//asign actual movemment in aux

}
void send_buffer(int n)//send buffer
{
    d='6';
    my_bot.bt.send_data(d); //set the slave robot in its start position
    switch(n)
    {
        case 2: delay(500); break;
        case 3: delay(1000); break;
        case 4: delay(1500); break;
    }
    d='0';
    my_bot.bt.send_data(d); //stop the slave robot when it's int the start position
    delay(1000);
    for(int posm=0; posm<buffer_size-1; posm=posm+2)//sends the buffer
    {
        switch (buffer[posm])
        {
            case 1: d='1'; break;
            case 2: d='2'; break;
            case 3: d='3'; break;
            case 4: d='4'; break;
            case 5: d='5'; break;
            case 6: d='6'; break;
            default: d='6'; break;
        }
        my_bot.bt.send_data(d);
        for(int vcycle=0; vcycle < buffer[posm+1] + 1; vcycle ++)
        {
            delay(100);
        }//wait until each movemment cycle has ended
    }
    d='6';
    my_bot.bt.send_data(d);
    switch(n)
    {
        case 2: delay(1500); break;
        case 3: delay(1000); break;
        case 4: delay(500); break;
    }
    d='0';
    my_bot.bt.send_data(d); //stop the slave robot
}



