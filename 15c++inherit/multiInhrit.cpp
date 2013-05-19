#include <iostream>
using namespace std;
/*含有纯虚函数的类，称为抽象类，不可以定义抽象类的对象*/
/*
 *抽象类不能直接构造出对象，除此之外，可以做任何能做的事情。
 *    做函数的参数，用来声明指针，或是引用类型
 */
class Shape{
public:
        virtual void show()const=0;       /*纯虚函数，没有函数体*/
};

class AutoCAD{
public:
        void draw(const Shape& s);
        
};
void AutoCAD::draw(const Shape& s)
{
        s.show();
}

class Square:public Shape{
public:
        Square(){}
        void show()const ;
        
};
void Square::show()const
{
        cout<<"-----"<<endl;
        cout<<"|   |"<<endl;
        cout<<"|   |"<<endl;
        cout<<"-----"<<endl;
}

class Rect:public Shape{
public:
        void show() const;
};
void Rect::show() const
{
        cout<<"-----"<<endl;
        cout<<"|   |"<<endl;
        cout<<"|   |"<<endl;
        cout<<"|   |"<<endl;
        cout<<"-----"<<endl;
}

int main()
{
        Square sq;
        AutoCAD autoCAD;
        autoCAD.draw(sq);
        Rect rect;
        autoCAD.draw(rect);
        
        return 0;    
}
