#include <iostream>
#include <typeinfo>
using namespace std;

class A{
public:
        virtual void show(){}
};
class B:public A{
        
};
class C:public B{
        
};
class D:public B{
        
};

void fa(A& a)
{
        if(typeid(a)==typeid(A))
                cout<<'A'<<endl;
        else if(typeid(a)==typeid(B))
                cout<<'B'<<endl;
        else if(typeid(a)==typeid(C))
                cout<<'C'<<endl;
        else if(typeid(a)==typeid(D))
                cout<<'D'<<endl;
        else
                cout<<"ERROR"<<endl;
}

int main()
{
        A* pa=new C;
        cout<<typeid(*pa).name()<<endl;
        if(typeid(*pa)==typeid(C))            /*常这样使用*/
                cout<<"pa指向一个C对象"<<endl;
        fa(*pa);
        
        return 0;    
}
