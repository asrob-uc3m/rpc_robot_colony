#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_pushButton_clicked();

        void on_pushButton_up_clicked();

        void on_pushButton_left_clicked();

        void on_pushButton_right_clicked();

        void on_pushButton_down_clicked();

        void on_pushButton_stop_clicked();

        void on_pushButton_2_clicked();

        void keyPressEvent(QKeyEvent *event);

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
