#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

enum Oper{
    oper_add,
    oper_sub,
    oper_mul,
    oper_dev,
    oper_invial
};

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_10_clicked();

    void on_Plus_clicked();

    void on_Sub_clicked();

    void on_Mul_clicked();

    void on_Dev_clicked();

    void on_Equal_clicked();

    void on_Clear_clicked();

private:
    Ui::Widget *ui;

private:
    int num;
    int tmp;
    enum Oper opera;

};

#endif // WIDGET_H
