/*
  如果自己重载了new，就必须自己定义delete
  C++保证在new调用结束后，类的构造函数一定会调用
  同样在调用delete之前，类的析构函数一定会调用

  new和new[]；delete和delete[]都是两个不同的操作符
  对new[]的空间是一次性分配的，但是多次调用构造函数
 */
#include <iostream>
#include <cstdlib>
using namespace std;

class Example{
        int x,y;
public:
        Example(int x=0,int y=0):x(x),y(y)
                             {
                                     cout<<"Example(int,int) called"<<endl;
                             }
        ~Example()
        {
                cout<<"~Example() called"<<endl;
        }
        void* operator new(size_t sz)
        {
                cout<<"operator new() called"<<endl;
                cout<<sz<<endl;
                return (void*)malloc(sz);
        }
        /*C++保证在new调用结束后，类的构造函数一定会调用*/
        /*同样在调用delete之前，类的析构函数一定会调用*/
        void* operator new[](size_t sz)
                {
                        cout<<"operator new[] called"<<endl
                            <<sz<<endl;
                        return (void*)malloc(sz);
                        
                }
        void operator delete(void* p)
                {
                        cout<<"delete() called"<<endl;
                        free(p);
                }
        void operator delete[](void *p)
                {
                        cout<<"delete[]() called"<<endl;
                        cout<<p<<endl;
                        free(p);
                }
};

int main()
        {
                Example* one=new Example(10,20);
                delete one;
                Example* two=new Example[5];
                delete [] two;
                return 0;
        }

/*
  result:
operator new() called
8
Example(int,int) called
~Example() called
delete() called
operator new[] called   
48                        里面有8B的结束标志
Example(int,int) called   另外，对于new[]所需要的空间是一次分配的，但是对多次调用构造函数
Example(int,int) called
Example(int,int) called
Example(int,int) called
Example(int,int) called
~Example() called
~Example() called
~Example() called
~Example() called
~Example() called
delete[]() called
0x1973030
 */
