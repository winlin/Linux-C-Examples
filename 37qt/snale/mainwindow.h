#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

//Snake move's step
const int HEIGHT=20;
const int WIDTH=20;
const int LENTH = 30;
const int TIME=200;
//Snake move direction
enum Direction{
    mUp, mDown, mLeft, mRight
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void keyPressEvent(QKeyEvent *);
    void setGame();

private:
    Ui::MainWindow *ui;

private:
    //Timer to decide the snake move time
    QTimer* timer;
    enum Direction direct;
    //Next target for snake to eat
    QLabel* nextTarget;
    QLabel* snakeBody[LENTH];

    //步进
    int MOVEVALUE;
    //定时时间ms

    //Snake's length
private slots:
    //Snake moving handle functon
    void updata();

};

#endif // MAINWINDOW_H
