#include "mainwindow.h"
#include "robotcontrolwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QtGui/qevent.h>
#include <QDebug>

QSerialPort arrayserial[6];
QString arraytextEdit[6];
int num_robots;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0;i<num_robots;i++)
    {
        arrayserial[i].close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    num_robots=0;
    arraytextEdit[0]= ui->textEdit_1->toPlainText();
    arraytextEdit[1]= ui->textEdit_2->toPlainText();
    arraytextEdit[2]= ui->textEdit_3->toPlainText();
    arraytextEdit[3]= ui->textEdit_4->toPlainText();
    arraytextEdit[4]= ui->textEdit_5->toPlainText();


    for(int i=0;i<5;i++){
        if(arraytextEdit[i]!=NULL){
            qDebug() << arraytextEdit[i];
            arrayserial[i].setPortName(arraytextEdit[i]);
            arrayserial[i].setBaudRate(QSerialPort::Baud38400);
            arrayserial[i].setDataBits(QSerialPort::Data8);
            arrayserial[i].setParity(QSerialPort::NoParity);
            arrayserial[i].setStopBits(QSerialPort::OneStop);
            arrayserial[i].setFlowControl(QSerialPort::NoFlowControl);
            arrayserial[i].open(QIODevice::WriteOnly);
            num_robots++;
        }
    }
}

void MainWindow::on_pushButton_up_clicked()
{
    for(int i=0;i<num_robots;i++){
        arrayserial[i].write("6");
    }
}

void MainWindow::on_pushButton_left_clicked()
{
    for(int i=0;i<num_robots;i++){
        arrayserial[i].write("4");
    }
}

void MainWindow::on_pushButton_right_clicked()
{
    for(int i=0;i<num_robots;i++){
        arrayserial[i].write("5");
    }
}

void MainWindow::on_pushButton_down_clicked()
{
    for(int i=0;i<num_robots;i++){
        arrayserial[i].write("1");
    }
}

void MainWindow::on_pushButton_stop_clicked()
{
    for(int i=0;i<num_robots;i++){
        arrayserial[i].write("0");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Left -> A
    if (event->key() == Qt::Key_A)
    {
        for(int i=0;i<num_robots;i++){
            arrayserial[i].write("4");
        }
    }
    // Right -> D
    if (event->key() == Qt::Key_D)
    {
        for(int i=0;i<num_robots;i++){
            arrayserial[i].write("5");
        }
    }
    // Up -> W
    if (event->key() == Qt::Key_W)
    {
        for(int i=0;i<num_robots;i++){
            arrayserial[i].write("6");
        }
    }
    // Down -> S
    if (event->key() == Qt::Key_S)
    {
        for(int i=0;i<num_robots;i++){
            arrayserial[i].write("1");
        }
    }
    // Stop -> X
    if (event->key() == Qt::Key_X)
    {
        for(int i=0;i<num_robots;i++){
            arrayserial[i].write("0");
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    delete ui;
    for(int i=0;i<num_robots;i++){
        arrayserial[0].close();
    }

}
