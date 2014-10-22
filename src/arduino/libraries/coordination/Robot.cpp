/**
 * @file    Robot.cpp
 * @brief   Robot class implementation with movemment functions
 *
 * @author  María Blázquez Partido <maria.b.partido@alumnos.uc3m.es>
 * @date    2014-08
 *
 *  -- Asociacion de Robotica, University Carlos III of Madrid
 */

#include "Robot.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
Robot::Robot()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Robot::~Robot()
{
    _sm_r.my_servo.detach();
    _sm_l.my_servo.detach();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Robot::Robot(int robot_ID,int smr,int sml,int echor,int echol,int triggerr,int triggerl, int key, int power):_sm_r(smr),_sm_l(sml),us_r(echor,triggerr),us_l(echol, triggerl),bt(key,power)
{
    _robot_ID=robot_ID;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Robot::Robot(const Robot& rc):_sm_r(rc._sm_r), _sm_l(rc._sm_l)
{
    _robot_ID=rc._robot_ID;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int Robot::get_ID()
{ 
    return _robot_ID;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::move_forward(int speed)
{
    _sm_r.my_servo.attach(_sm_r.get_pin());
    _sm_l.my_servo.attach(_sm_l.get_pin());

    switch (_robot_ID)
    {
        case 1:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(99);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(103);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(111);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(180);}
            break;
        case 2:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(100);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(105);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(112);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(180);}
            break;
        case 3:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(105);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(108);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(111);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(180);}
            break;
        case 4:
            if(speed==1){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(98);}
            if(speed==2){ _sm_r.my_servo.write(85); _sm_l.my_servo.write(103);}
            if(speed==3){ _sm_r.my_servo.write(80); _sm_l.my_servo.write(110);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(180);}
            break;
        case 5:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(100);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(105);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(111);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(180);}
            break;
        default:
            break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::move_back(int speed)
{
    _sm_r.my_servo.attach(_sm_r.get_pin());
    _sm_l.my_servo.attach(_sm_l.get_pin());

    switch (_robot_ID)
    {
        case 1:
            if(speed==1){ _sm_r.my_servo.write(98); _sm_l.my_servo.write(87);}
            if(speed==2){ _sm_r.my_servo.write(104); _sm_l.my_servo.write(81);}
            if(speed==3){ _sm_r.my_servo.write(109); _sm_l.my_servo.write(76);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(0);}
            break;
        case 2:
            if(speed==1){ _sm_r.my_servo.write(98); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(104); _sm_l.my_servo.write(82);}
            if(speed==3){ _sm_r.my_servo.write(109); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(0);}
            break;
        case 3:
            if(speed==1){ _sm_r.my_servo.write(101); _sm_l.my_servo.write(91);}
            if(speed==2){ _sm_r.my_servo.write(106); _sm_l.my_servo.write(86);}
            if(speed==3){ _sm_r.my_servo.write(111); _sm_l.my_servo.write(81);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(0);}
            break;
        case 4:
            if(speed==1){ _sm_r.my_servo.write(101); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(107); _sm_l.my_servo.write(82);}
            if(speed==3){ _sm_r.my_servo.write(112); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(0);}
            break;
        case 5:
            if(speed==1){ _sm_r.my_servo.write(98); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(104); _sm_l.my_servo.write(82);}
            if(speed==3){ _sm_r.my_servo.write(109); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(0);}
            break;

        default:
            break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::turn_right(int speed)
{
    _sm_r.my_servo.attach(_sm_r.get_pin());
    _sm_l.my_servo.attach(_sm_l.get_pin());

    switch (_robot_ID)
    {
        case 1:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(104);}
            if(speed==2){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(180);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(180);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(180);}
            break;
        case 2:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(105);}
            if(speed==2){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(180);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(180);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(180);}
            break;
        case 3:
            if(speed==1){ _sm_r.my_servo.write(101); _sm_l.my_servo.write(101);}
            if(speed==2){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(180);}
            if(speed==3){ _sm_r.my_servo.write(111); _sm_l.my_servo.write(111);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(180);}
            break;
        case 4:
            if(speed==1){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(103);}
            if(speed==2){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(180);}
            if(speed==3){ _sm_r.my_servo.write(80); _sm_l.my_servo.write(180);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(180);}
            break;
        case 5:
            if(speed==1){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(103);}
            if(speed==2){ _sm_r.my_servo.write(90); _sm_l.my_servo.write(180);}
            if(speed==3){ _sm_r.my_servo.write(80); _sm_l.my_servo.write(180);}
            if(speed==4){ _sm_r.my_servo.write(180); _sm_l.my_servo.write(180);}
            break;
        default:
            break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::turn_left(int speed)
{
    switch (_robot_ID)
    {
        case 1:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(87);}
            if(speed==2){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(95);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(76);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(0);}
            break;
        case 2:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(95);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(0);}
            break;
        case 3:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(91);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(86);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(81);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(95);}
            break;
        case 4:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(82); _sm_l.my_servo.write(82);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(95);}
            break;
        case 5:
            if(speed==1){ _sm_r.my_servo.write(87); _sm_l.my_servo.write(88);}
            if(speed==2){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(95);}
            if(speed==3){ _sm_r.my_servo.write(77); _sm_l.my_servo.write(77);}
            if(speed==4){ _sm_r.my_servo.write(0); _sm_l.my_servo.write(0);}
            break;
        default:
            break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::stop_robot()
{
    _sm_r.my_servo.write(90); _sm_l.my_servo.write(95);
}
