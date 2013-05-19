#include <QApplication>
#include <QDialog>
#include "login.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    Login* w=new Login;
    //w->show();

    QDialog* d = new QDialog;
    d->resize(250,200);
    QLabel* label = new QLabel("Welcome!",d);

    //检查LOGIN窗口最终的返回状态
    if(w->exec()==QDialog::Accepted){
        d->show();
        app.exec();
    }

    return 0;
}
