#include <iostream>
using namespace std;

class A{
public:
        virtual void m1(){}
        virtual void m2()throw(int,double){}
        virtual void m3()throw(int){}
        virtual void m4()throw(){}
};
class B:public A{
        virtual void m1()throw(int){}          //OK
        virtual void m2()throw(int){}          //OK
        virtual void m3()throw(int,double){}   //NO looser(放送) throw specifier for ‘virtual void B::m4()
        virtual void m4()                      //NO   
};


int main()
{
        A* p=new B;
        try{
                p->m3();
        }
        catch(int){
                
        }
        
        return 0;    
}
