#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tmp=num=0;
    opera=oper_invial;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button_1_clicked()
{
    num=num*10+1;
    ui->ShowResult->display(num);
}

void Widget::on_Button_2_clicked()
{
    num=num*10+2;
    ui->ShowResult->display(num);
}

void Widget::on_Button_3_clicked()
{
    num=num*10+3;
    ui->ShowResult->display(num);
}

void Widget::on_Button_4_clicked()
{
    num=num*10+4;
    ui->ShowResult->display(num);
}

void Widget::on_Button_5_clicked()
{
    num=num*10+5;
    ui->ShowResult->display(num);
}

void Widget::on_Button_6_clicked()
{
    num=num*10+6;
    ui->ShowResult->display(num);
}

void Widget::on_Button_7_clicked()
{
    num=num*10+7;
    ui->ShowResult->display(num);
}

void Widget::on_Button_8_clicked()
{
    num=num*10+8;
    ui->ShowResult->display(num);
}

void Widget::on_Button_9_clicked()
{
    num=num*10+9;
    ui->ShowResult->display(num);
}

void Widget::on_Button_10_clicked()
{
    num=num*10;
    ui->ShowResult->display(num);
}

void Widget::on_Plus_clicked()
{
    if(tmp!=0){
	on_Equal_clicked();
    }
	opera=oper_add;
	 tmp=num;
	 num=0;
}
void Widget::on_Sub_clicked()
{
    if(tmp!=0){
	on_Equal_clicked();
    }
	opera=oper_sub;
	 tmp=num;
	 num=0;
}

void Widget::on_Mul_clicked()
{
    if(tmp!=0){
	on_Equal_clicked();
    }
	opera=oper_mul;
	 tmp=num;
	 num=0;
}

void Widget::on_Dev_clicked()
{
    if(tmp!=0){
	on_Equal_clicked();
    }
	opera=oper_dev;
	 tmp=num;
	 num=0;
}

void Widget::on_Equal_clicked()
{
    switch(opera){
    case 0:
	num+=tmp;
	break;
    case 1:
       num=tmp-num;
	break;
    case 2:
	num*=tmp;
	break;
    case 3:
	num=tmp/num;
	break;
    default:
	num=0;
    }
    opera=oper_invial;
    tmp=0;
    ui->ShowResult->display(num);
}

void Widget::on_Clear_clicked()
{
    num=tmp=0;
    opera=oper_invial;
    ui->ShowResult->display(num);
}
