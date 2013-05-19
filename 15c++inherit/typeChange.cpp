/*
 *使用dynamic_cast<>()的前提是父类含有虚函数
 *如果转换成功，返回地址，否则返回0
 *它会先判断两个类型是否可以转换
 */
#include <iostream>
using namespace std;

class A{
public:
        virtual void show(){}
};
class B:public A{
public:
        virtual void show(){}
        virtual void bm(){cout<<"bm"<<endl;}
};
class C:public A{
public:
        virtual void show(){}
        virtual void cm(){cout<<"cm"<<endl;}
};

int main()
{
        A* pa=new B;
        B* pb=(B*)pa;
        C* pc=(C*)pb;  /*强制类型转换具有风险*/
        pc->cm();      /*输出的却是"bm",调用混乱*/
        B* pbb=dynamic_cast<B*>(pa);
        pbb->bm();
        
        C* pcc=dynamic_cast<C*>(pbb);
        if(pcc==NULL){
                cout<<"B*-->C* failed"<<endl;
        }
        
        return 0;    
}
