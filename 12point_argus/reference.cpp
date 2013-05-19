#include <iostream>
using namespace std;
/*引用的本质是多个标识符都代表同一块内存空间;引用实际上使用指针来实现的*/
int main(  )
        {
                int x=10;
                int& r=x;
                cout<<r<<endl;
                cout<<&x<<endl;
                cout<<&r<<endl;

                int y=20;
                r=y; //x=y;不是起别名，引用只能一直指向一个变量
                //int& r2=100; 不可以使用一个非const的引用指向一个const值
                const int& r2=100;   //可以
                //r2=300;  //ERROR,const 不可赋值
                int& ra=x;  //一个变量可以有多个别名
                int& rb=r;  //可以使用一个引用去初始化另一个引用
                
                
                
                
                return 0;
        }
