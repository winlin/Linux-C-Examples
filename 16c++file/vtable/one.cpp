#include <iostream>
#include <cstdio>
using namespace std;

class Base1{
private:
        int base1;
public:
        Base1(int i=100):base1(i){}
        virtual void f(){cout<<"Base1::f"<<endl;}
        virtual void g(){cout<<"Base1::g"<<endl;}
        virtual void h(){cout<<"Base1::h"<<endl;}
};

class Base2{
public:
        int base2;
public:
        Base2(int i=200):base2(i){}
        virtual void f(){cout<<"Base2::f"<<endl;}
        virtual void g(){cout<<"Base2::g"<<endl;}
        virtual void h(){cout<<"Base2::h"<<endl;}
};
class Base3{
private:
        int base3;
public:
        Base3(int i=300):base3(i){}
        virtual void f(){cout<<"Base3::f"<<endl;}
        virtual void g(){cout<<"Base3::g"<<endl;}
        virtual void h(){cout<<"Base3::h"<<endl;}        
};
class Derive:public Base1,public Base2,public Base3{
private:
        int derive;
public:
        Derive(int i=400):derive(i){}
        virtual void f(){cout<<"Derive::f"<<endl;}
        virtual void g1(){cout<<"Derive::g1"<<endl;}
};

typedef void(*Fun)(void);

int main()
{
        Fun pFun=NULL;

        Derive d;
        long** pVtab=(long**)&d;
        
        cout<<"hello world"<<endl;
        
        return 0;    
}
