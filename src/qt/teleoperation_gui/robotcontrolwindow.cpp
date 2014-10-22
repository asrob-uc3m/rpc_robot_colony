#include "robotcontrolwindow.h"
#include "ui_robotcontrolwindow.h"
//#include <QtGui/qevent.h>

robotcontrolwindow::robotcontrolwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::robotcontrolwindow)
{
    ui->setupUi(this);
}

robotcontrolwindow::~robotcontrolwindow()
{
    delete ui;
}


void robotcontrolwindow::on_pushButton_up_clicked()
{

}

void robotcontrolwindow::on_pushButton_down_clicked()
{

}

void robotcontrolwindow::on_pushButton_left_clicked()
{

}

void robotcontrolwindow::on_pushButton_right_clicked()
{

}

void robotcontrolwindow::on_pushButton_stop_clicked()
{

}

//void robotcontrolwindow::keyPressEvent(QKeyEvent *event)
//{
//    //Left->A
//    if (event->key() == Qt::Key_A)
//    {
//        /* Codigo Left */
//    }
//    //Right->D
//    if (event->key() == Qt::Key_D)
//    {
//        /* Codigo Right */
//    }
//    //Up -> W
//    if (event->key() == Qt::Key_W)
//    {
//        /* Codigo Up */
//    }
//    //Down -> S
//    if (event->key() == Qt::Key_S)
//    {
//        /* Codigo Down */
//    }
//    //Stop -> X
//    if (event->key() == Qt::Key_X)
//    {
//        /* Codigo Stop */
//    }
//}
