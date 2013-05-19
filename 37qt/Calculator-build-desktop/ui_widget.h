/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Aug 23 18:01:19 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLCDNumber *ShowResult;
    QGridLayout *gridLayout;
    QPushButton *Button_1;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Plus;
    QPushButton *Button_4;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_7;
    QPushButton *Button_8;
    QPushButton *Button_9;
    QPushButton *Button_10;
    QPushButton *Equal;
    QPushButton *Mul;
    QPushButton *Sub;
    QPushButton *Dev;
    QPushButton *Clear;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(423, 226);
        gridLayout_4 = new QGridLayout(Widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ShowResult = new QLCDNumber(Widget);
        ShowResult->setObjectName(QString::fromUtf8("ShowResult"));
        ShowResult->setSmallDecimalPoint(false);
        ShowResult->setNumDigits(33);
        ShowResult->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(ShowResult, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button_1 = new QPushButton(Widget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));

        gridLayout->addWidget(Button_1, 0, 0, 1, 1);

        Button_2 = new QPushButton(Widget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));

        gridLayout->addWidget(Button_2, 0, 1, 1, 1);

        Button_3 = new QPushButton(Widget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));

        gridLayout->addWidget(Button_3, 0, 2, 1, 1);

        Plus = new QPushButton(Widget);
        Plus->setObjectName(QString::fromUtf8("Plus"));

        gridLayout->addWidget(Plus, 0, 3, 1, 1);

        Button_4 = new QPushButton(Widget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));

        gridLayout->addWidget(Button_4, 1, 0, 1, 1);

        Button_5 = new QPushButton(Widget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));

        gridLayout->addWidget(Button_5, 1, 1, 1, 1);

        Button_6 = new QPushButton(Widget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));

        gridLayout->addWidget(Button_6, 1, 2, 1, 1);

        Button_7 = new QPushButton(Widget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));

        gridLayout->addWidget(Button_7, 2, 0, 1, 1);

        Button_8 = new QPushButton(Widget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));

        gridLayout->addWidget(Button_8, 2, 1, 1, 1);

        Button_9 = new QPushButton(Widget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));

        gridLayout->addWidget(Button_9, 2, 2, 1, 1);

        Button_10 = new QPushButton(Widget);
        Button_10->setObjectName(QString::fromUtf8("Button_10"));

        gridLayout->addWidget(Button_10, 3, 0, 1, 1);

        Equal = new QPushButton(Widget);
        Equal->setObjectName(QString::fromUtf8("Equal"));

        gridLayout->addWidget(Equal, 3, 2, 1, 1);

        Mul = new QPushButton(Widget);
        Mul->setObjectName(QString::fromUtf8("Mul"));

        gridLayout->addWidget(Mul, 2, 3, 1, 1);

        Sub = new QPushButton(Widget);
        Sub->setObjectName(QString::fromUtf8("Sub"));

        gridLayout->addWidget(Sub, 1, 3, 1, 1);

        Dev = new QPushButton(Widget);
        Dev->setObjectName(QString::fromUtf8("Dev"));

        gridLayout->addWidget(Dev, 3, 3, 1, 1);

        Clear = new QPushButton(Widget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        gridLayout->addWidget(Clear, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        Button_1->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        Button_2->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        Button_3->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        Plus->setText(QApplication::translate("Widget", "+", 0, QApplication::UnicodeUTF8));
        Button_4->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        Button_5->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        Button_6->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        Button_7->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        Button_8->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        Button_9->setText(QApplication::translate("Widget", "9", 0, QApplication::UnicodeUTF8));
        Button_10->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        Equal->setText(QApplication::translate("Widget", "=", 0, QApplication::UnicodeUTF8));
        Mul->setText(QApplication::translate("Widget", "*", 0, QApplication::UnicodeUTF8));
        Sub->setText(QApplication::translate("Widget", "-", 0, QApplication::UnicodeUTF8));
        Dev->setText(QApplication::translate("Widget", "/", 0, QApplication::UnicodeUTF8));
        Clear->setText(QApplication::translate("Widget", "CE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
