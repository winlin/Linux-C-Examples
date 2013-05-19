/*
 *其实，该例子并没有很好的演示虚继承的作用，在基类里面应该只包含
 *所有子类都共有的且相同的属性，或者所有子类共有但是具体实现不一样
 *的成员方法。
 */
#include <iostream>
using namespace std;

class Goods{
        double price;
public:
        Goods(double p):price(p){cout<<"Goods(double)"<<endl;}
        ~Goods(){}
        double getPrice(){return price;}
};

class Phone:virtual public Goods{
public:
        Phone(double price=100.0):Goods(price){cout<<"Phone(double)"<<endl;}
        ~Phone(){cout<<"~Phone()"<<endl;}
};

class Mp3:virtual public Goods{
public:
        Mp3(double price=200.0):Goods(price){cout<<"Mp3(double)"<<endl;}
        ~Mp3(){cout<<"~Mp3()"<<endl;}
};

class Camera:virtual public Goods{
public:
        Camera(double price=300.0):Goods(price){cout<<"Camera(double)"<<endl;}
        ~Camera(){cout<<"~Camera()"<<endl;}
};

class CellPhone:public Phone,public Mp3,public Camera{
public:
        CellPhone(double p1=100.0,double p2=200.0,double p3=300.0)
                :Goods(p3+p1+p2){cout<<"CellPhone()"<<endl;}
        ~CellPhone(){cout<<"~CellPhone()"<<endl;}
};

int main()
        {
                CellPhone c;
                cout<<c.getPrice()<<endl;
                return 0;
        }

/*
构造和析构的顺序：
Phone(double)
Mp3(double)
Camera(double)
CellPhone()
~CellPhone()
~Camera()
~Mp3()
~Phone()
 */
