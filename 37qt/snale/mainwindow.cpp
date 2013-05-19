#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(123456);
    snakeBody[0] = new QLabel(this);
    //set the background
    //1.allow set background
    snakeBody[0]->setAutoFillBackground(true);
    //2.set palette 设置调色板
    snakeBody[0]->setPalette(QPalette(QColor(qrand()%200,qrand()%150,qrand()%100)));
    //设置蛇头的大小
    snakeBody[0]->resize(QSize(WIDTH,HEIGHT));
    //设置边框为突起
    snakeBody[0]->setFrameShadow(QFrame::Raised);
    //设置形状
    snakeBody[0]->setFrameShape(QFrame::Panel);
    //初始化蛇的身体
    for(int i=1;i<LENTH;++i)
	snakeBody[i]=NULL;

    //开始时蛇移动的方向
     direct=mRight;

     //设置目标
     nextTarget=new QLabel(this);
     nextTarget->setAutoFillBackground(true);
     nextTarget->setPalette(QPalette(QColor(100,100,100)));
     nextTarget->resize(QSize(WIDTH,HEIGHT));
     nextTarget->setFrameShadow(QFrame::Raised);
     nextTarget->setFrameShape(QFrame::Panel);
     MOVEVALUE=WIDTH;
    //将目标放到一个位置，坐标为MOVEVALUE的倍数
     nextTarget->move(3*MOVEVALUE,5*MOVEVALUE);
     //设置蛇头的位置
     snakeBody[0]->move(4*MOVEVALUE,3*MOVEVALUE);

     //改变窗口的标题
     this->setWindowTitle("Snake");
     //初始化定时器
     timer = new QTimer(this);
     //将定时器的溢出信号 和自己的槽函数链接起来
     connect(timer,SIGNAL(timeout()),this,SLOT(updata()));
     //开启定时器
     timer->start(TIME);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//当用户按下键时，该函数就会被调用
void MainWindow::keyPressEvent(QKeyEvent * k)
{
    if(k->key() == Qt::Key_Left){
	direct = mLeft;
    }
    else if(k->key() == Qt::Key_Right){
	direct = mRight;
    }
    else if(k->key() == Qt::Key_Up){
	direct = mUp;
    }
    else if(k->key() == Qt::Key_Down){
	direct = mDown;
    }
    else if(k->key() == Qt::Key_Space){
	if(timer->timerId()!=-1)
	     timer->stop();
	else
	    timer->start();
    }
}

void MainWindow::updata()
{
    //定义几个保存位置的变量
    //当前位置
    int x=0,y=0;
    //下一步要移动的位置
    int nextX=0,nextY=0;

    nextX=x = snakeBody[0]->x();
    nextY=y = snakeBody[0]->y();
     //检测蛇头当前的位置是否碰到边框
    if(x<=0 || y<=16 || x>=this->width()-16 || y>=this->height()-16){
	QMessageBox box;
	box.setWindowTitle("GAME OVER");
	box.setText("YOU LOSE GAME");
	box.setStandardButtons(QMessageBox::Ok);
	box.exec();
	qApp->quit();
    }

    //根据蛇头移动的方向确定下一个位置的坐标
    switch(direct){
    case 0:
	nextY = y-MOVEVALUE;
	break;
    case 1:
	nextY = y+MOVEVALUE;
	break;
    case 2:
	nextX = x-MOVEVALUE;
	break;
    case 3:
	nextX = x+MOVEVALUE;
	break;
    }
    //碰撞检测
    if(nextX==nextTarget->x() && nextY==nextTarget->y()){
	    //将该目标放到蛇的身体里面
	   int i=LENTH;
	   while(snakeBody[--i]==NULL);
	   if(i==LENTH-1){
	       QMessageBox box;
	       box.setWindowTitle("Congratulation");
	       box.setText("Congratulation! YOU WIN THE GAME");
	       box.setStandardButtons(QMessageBox::Ok);
	       box.exec();
	       qApp->quit();
	   }
	   //将蛇身向后移动一个位置
	   while(i>=0 && i<LENTH-1){
	       snakeBody[i+1]=snakeBody[i];
	       i--;
	   }
	   //将目标设置为蛇头
	   snakeBody[0]=nextTarget;

	   //生成下一个目标
	   nextTarget=new QLabel(this);
	   nextTarget->setAutoFillBackground(true);
	   nextTarget->setPalette(QPalette(QColor(100,100,100)));
	   nextTarget->resize(QSize(WIDTH,HEIGHT));
	   nextTarget->setFrameShadow(QFrame::Raised);
	   nextTarget->setFrameShape(QFrame::Panel);

	   //将目标放到一个位置，坐标为MOVEVALUE的倍数
	   int xTmp=qrand()%(this->width());
	   int yTmp=qrand()%(this->height());
	   xTmp=xTmp-xTmp%WIDTH;
	   yTmp=yTmp-yTmp%WIDTH;
	  //防止位置在死角
	   if(xTmp<=WIDTH)
	       xTmp+=2*WIDTH;
	   else if(xTmp>=(this->width()-16))
	       xTmp-=2*WIDTH;
	   if(yTmp<=WIDTH)
	       yTmp+=2*WIDTH;
	   else if(yTmp>=(this->width()-16))
	       yTmp-=2*WIDTH;

	   nextTarget->move(xTmp,yTmp);
	   nextTarget->show();
    }
    //移动蛇的身体，后一块等于前一块的坐标
    int i=LENTH;
    while(snakeBody[--i]==NULL);
    while(i>0){
	snakeBody[i]->move(snakeBody[i-1]->x(),snakeBody[i-1]->y());
	i--;
    }
    snakeBody[0]->move(nextX,nextY);
}

void MainWindow::setGame()
{

    QMessageBox box;
    box.setWindowTitle("Set Your Game");

}
