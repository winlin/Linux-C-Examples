/*
 *对于窗口的布局，两种方式：move() 和 窗口布局管理器
 */
#include "button.h"

MyWidget::MyWidget(QWidget* parent):QWidget(parent)
{
	//申请空间
	label = new QLabel(this);
	button = new QPushButton(this);
	//设置显示文字
	label->setText("Morning");
	button->setText("Change");
	//默认情况下，label和button都是出现在窗口的左上角
	//不设置位置的话，会出现覆盖现象
	//button->move(0,20);

	//将信号和槽函数连接起来
	//一旦发射这个信号，就会执行该槽函数
	connect(button,SIGNAL(clicked()),this,SLOT(changeText()));

	//初始化flag
	flag=true;
	//重定义label的大小
	label->resize(50,20);

	exit = new QPushButton("Eixt",this);
	//exit->move(80,0);
	connect(exit,SIGNAL(clicked()),this,SLOT(close()));


	//注释掉各个组件的move()，然后通过水平布局管理器来管理各个组件的水平顺序
	layout = new QHBoxLayout(this);
	layout->addWodget(label);
	layout->addWodget(button);
	layout->addWodget(exit);
	//设置窗体的布局管理器
	this->setLayout(layout);
}

//槽函数实现
void MyWidget::changeText()
{
	//向终端输出调试信息
	qDebug("Change Text...");
	if(flag){
		label->setText("Afternoon...");
		flag=false;
	}
	else{
		label->setText("Morning");
		flag=true;
	}
		
}
