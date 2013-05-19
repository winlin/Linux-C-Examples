/*子类可以继承父类的static成员函数，
  另外，子类中的同名函数也会覆盖父类的static函数
 */
#include <iostream>
using namespace std;

class Parent{
public:
        static void show()
                {
                        cout<<"inherit the Parent static function "<<endl;
                }
};

class Child:public Parent{
public:
        static void childShow()
                {
                        cout<<"Child static function "<<endl;
                }
        static void show()
                {
                        cout<<"Child static function"<<endl;
                }
};

int main()
        {
                Child c;
                c.show();
                return 0;
        }
