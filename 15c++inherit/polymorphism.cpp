/*
 *编译期绑定(静态绑定)
 *pa的类型是什么？
 *     Animal  编译期类型
 *     Dog     运行期类型
 *
 *在成员函数前面添加virtual，就会使其称为多态函数
 *一旦父类的成员函数前添加了virtual,那么子类的同名函数默认为virtual
 *同名函数实现 覆盖override：
 *           1.函数名相同，参数相同，返回值相同
 *           2.访问权限不能更小
 *           3.抛出的异常不能更多
 */
#include <iostream>
using namespace std;

class Animal{
public:
        void eat(){cout<<"eating"<<endl;}
        void sleep(){cout<<"sleeping"<<endl;}
        virtual void run(){cout<<"run"<<endl;}   /*多态的体现*/
};
class Dog:public Animal{
public:
        void eat(){cout<<"Dog eating"<<endl;}
        void sleep(){cout<<"Dog sleeping"<<endl;}
        void run(){cout<<"Dog is running"<<endl;}
        void watchHome(){cout<<"Dog Watching Home"<<endl;}
};
class Cat:public Animal{
public:
        void eat(){cout<<"Cat eating"<<endl;}
        void sleep(){cout<<"Cat sleeping"<<endl;}
        void run(){cout<<"Cat is running"<<endl;}
        void catchMouse(){cout<<"Cat is catching the mouse"<<endl;}
};

int main()
        {
                Dog d;
                d.eat();
                d.watchHome();

                Dog* pd=new Dog();
                pd->eat();
                pd->watchHome();
                cout<<"-----------------"<<endl;
                Animal* pa=new Dog();
                pa->eat();
                pa->sleep();
                pa->run();
                //pa->watchHome();              /*error: ‘class Animal’ has no member named ‘watchHome’*/

                Animal& ra=d;                   /*同父类的指针一样，编译期绑定*/
                ra.eat();
                ra.sleep();
                ra.run();
                
                cout<<"------------------"<<endl;
                Cat* cat=new Cat();
                pa=cat;
                pa->eat();
                pa->sleep();
                pa->run();
                //pa->catchMouse()
                
                Animal& rb=*cat;
                rb.run();
                rb.eat();
                
                return 0;
        }
