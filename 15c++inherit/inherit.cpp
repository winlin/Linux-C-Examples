/*子类只能对父类的 protected 和 public进行访问或操作 */
#include <iostream>
using namespace std;

class Parent{
private:
        int x;
protected:
        int y;
public:
        int z;
        
public:
        Parent(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
        void m1()
                {
                        cout<<x<<endl;
                }
        void m2()
                {
                        cout<<y<<endl;
                }
};
/*共有继承，不会改变父类数据成员的限制属性*/
class Child:public Parent{
public:
        void show()
                {
                        // ++x;    /*不可访问父类private成员*/
                        ++y;
                        ++z;
                }
};
/*私有继承，会把父类所有的成员都变成private*/
class Child2:private Parent{
public:
        void show()
                {
                        // ++x;    /*不可访问父类private成员*/
                        ++y;
                        ++z;
                }
};
/*保护继承，类似与私有继承，会把父类的public提升为protected，其他的不变*/
class Child3:protected Parent{
public:
        void show()
                {
                        // ++x;    /*不可访问父类private成员*/
                        ++y;
                        ++z;
                }
};

int main()
{
        Child c;
        c.m1();
        c.m2();
        return 0;
}
