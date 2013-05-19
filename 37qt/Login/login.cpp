#include  "login.h"
#include <QMessageBox>
Login::Login(QWidget* parent):QDialog(parent)
{
    usrLabel = new QLabel;
    pwdLabel = new QLabel;
    usrLabel->setText("&UserName");
    pwdLabel->setText("&Password");

    usrLineEdit = new QLineEdit;
    pwdLineEdit = new QLineEdit;

    loginButton = new QPushButton;
    cancelButton = new QPushButton;
    loginButton->setText("Login");
    cancelButton->setText("Cancel");

    usrHLayout = new QHBoxLayout;
    usrHLayout->addWidget(usrLabel);
    usrHLayout->addWidget(usrLineEdit);

    pwdHLayout =new QHBoxLayout;
    pwdHLayout->addWidget(pwdLabel);
    pwdHLayout->addWidget(pwdLineEdit);

    buttonHLayout = new QHBoxLayout;
    buttonHLayout->addWidget(loginButton);
    buttonHLayout->addWidget(cancelButton);

    globalVLayout = new QVBoxLayout;
    globalVLayout->addLayout(usrHLayout);
    globalVLayout->addLayout(pwdHLayout);
    globalVLayout->addLayout(buttonHLayout);
    //设置全局的layout，setLayout()会自动更改组件的父窗口指针为this
    this->setLayout(globalVLayout);

    //设置label的伙伴
    usrLabel->setBuddy(usrLineEdit);
    pwdLabel->setBuddy(pwdLineEdit);

    //设置窗口标题
    this->setWindowTitle("LOGIN");

    //cancel按钮 信号与槽函数链接起来
    QObject::connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(loginButton,SIGNAL(clicked()),this,SLOT(loginClicked()));

    //修改pwdLineEdit的回显方式
    pwdLineEdit->setEchoMode(QLineEdit::Password);
}

void Login::loginClicked()
{
   // qDebug("login button clicked");
    QMessageBox box;
    if(usrLineEdit->text()=="admin"&&pwdLineEdit->text()=="123456"){
        box.setText("Login Success!");
        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        //box.setStandardButtons(QMessageBox::No);
        box.exec();
        //执行槽函数accept(),将返回状态设置为Accepted.
        this->accept();
    }
    else{
        box.setText("Your username or password error");
        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        //显示对话框，并等待用户动作
        box.exec();
        //清空用户名和密码
        usrLineEdit->clear();
        pwdLineEdit->clear();
        //光标定位到usrLineEdit里面
        usrLineEdit->setFocus();
    }
}
