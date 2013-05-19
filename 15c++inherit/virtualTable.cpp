#include <iostream>
using namespace std;
class A{
        int x;
public:
        void show(){}
};

class B{
        int x;
public:
        virtual void show(){}
        //virtual void display(){}
};

class C:public B{
public:
        virtual void show(){}
        virtual void display(){}
};

class D:public B{
public:
        virtual void show(){}
        virtual void display(){}
};


int main()
{
        A a;
        B b;
        cout<<"sizeof(A)"<<sizeof(a)<<endl;
        cout<<"sizeof(B)"<<sizeof(b)<<endl;
        cout<<"sizeof(C)"<<sizeof(C)<<endl;
        cout<<"sizeof(D)"<<sizeof(D)<<endl;
        return 0;    
}
