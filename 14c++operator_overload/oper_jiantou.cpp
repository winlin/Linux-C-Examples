/*
  重载“->”箭头运算符,返回一个对象的指针，相当于One.operator->()->function();
  重载“*”星号运算符
*/
#include <iostream>
using namespace std;

class Person{
        string name;
        int age;
public:
        Person(string name,int age):name(name),age(age){}
        void show()
                {
                        cout<<name<<" "<<age<<endl;
                }
};

class PS{
        Person* ps[100];   /*容量*/
        int size;          /*已放数量*/
        int index;         /*当前位置*/
public:
        PS():size(0),index(0){}
        void add(Person* p)
                {
                        ps[size++]=p;
                }
        bool operator++ ()
                {
                        if(index>=size-1)
                                return false;
                        ++index;
                        return true;
                }
        bool operator++ (int)
                {
                        return operator++();
                }
        Person* operator->()
        {
                return ps[index];
        }
        Person& operator*(){                 /*重载 *运算符 */
                return *ps[index];
        }
        
};

int main()
        {
                Person person[5]={
                        {"aa",19},{"bb",20},{"cc",23},{"dd",21},{"ee",25}
                };
                PS ps;
                for(int i=0;i<5;++i){
                        ps.add(person+i);
                }
                while(1){
                        ps->show();
                        //ps.operator->()->show();
                        if(!(++ps))break;
                }
                return 0;
        }
