#ifndef ROBOTCONTROLWINDOW_H
#define ROBOTCONTROLWINDOW_H

#include <QDialog>

namespace Ui {
class robotcontrolwindow;
}

class robotcontrolwindow : public QDialog
{
    Q_OBJECT

public:
    explicit robotcontrolwindow(QWidget *parent = 0);
    ~robotcontrolwindow();

private slots:
    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_stop_clicked();

    //void keyPressEvent(QKeyEvent *event);
private:
    Ui::robotcontrolwindow *ui;
};

#endif // ROBOTCONTROLWINDOW_H
