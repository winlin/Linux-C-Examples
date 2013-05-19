#include <QApplication>
#include "button.h"

int main(int argc,char** argv)
{
	//生成一个QApplication对象，管理程序资源
	QApplication app(argc,argv);

	//生成一个MyWidget对象
	MyWidget* w = new MyWidget;
	//显示窗体
	w->show();
	
	w->close();
	//进入事件循环状态，等待用户的动作
	return app.exec();
	
}
