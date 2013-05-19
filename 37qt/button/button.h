#ifndef _BUTTON_H
#define _BUTTON_H

#include <QLabel>
#include <QPushButton>
#include <QLayout>

class MyWidget:public QWidget{
        //如果类定义中包含 信号或者槽函数 时必须包含这个宏
	//槽函数一般为私有
	Q_OBJECT
public:
	MyWidget(QWidget* parent=0);
private:
	//显示文字
	QLabel* label;
	QButton* button;
	QPushButton* exit;
	bool flag;
	QHBoxLayout* layout;
	
private slots:
	//私有槽函数
	void changText();
	void close();
};

#endif
