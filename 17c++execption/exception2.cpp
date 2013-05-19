#include <iostream>
using namespace std;

void m5()throw(const char*)
{
        throw "SQLException";
}

void m4()
{
        try{
                m5();
        }catch(const char* e){
                cout<<"make a log"<<endl;
                /*再次抛出*/
                throw;
        }
}

void m3()
{
        m4();
        /*直接再次抛出*/
        
}

void m2()
{
        try{
                m3();
        }catch(const char* e){
                cout<<"Handle the exception:"<<e<<endl;
                /*处理异常，导致新异常抛出*/
                throw "Server Exception";
        }
}

void m1()
{
        try{
                m2();
        }catch(...){
                cout<<"处理异常"<<endl;
                /*处理所有异常*/
        }
        cout<<"系统繁忙，请稍候再试"<<endl;
}

int main()
{
        m1();
        return 0;    
}
