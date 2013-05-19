#ifndef LOGIN_H
#define LOGIN_H

#include <QLable>
#include <QPushButton>
#include <QLineEdit>

class Login:public QWidget(QWidget* parent=0){
public:
	Login(QWidget* parent=0);
private:
	QLable* usrLabel;
	QLable* pwdLabel;
	QLineEdit* usrLineEdit;
	QLineEdit* pwdLineEdit;
	QPushButton* LoginButton;
	QPushButton* cancelButton;

	QHBoxLayout* usrHLayout;
	QHBoxLayout* pwdHLayout;
	QHBoxLayout* buttonHLayout;
	QVBoxLayout* globalVLayout;
}

#endif
