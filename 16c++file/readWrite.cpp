#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Person{
        int id;
        char name[10];
        int age;
public:
        Person(int id,const char* name,int age)
                :id(id),age(age)
                 {
                         strcpy(this->name,name);
                 }
        friend ostream& operator<<(ostream& os,const Person& p)
                {
                        return os<<p.id<<","<<p.name<<","<<p.age<<endl;
                }
};

int main()
{
        Person ps[3]={
                Person(1,"aaa",20),
                Person(2,"bbb",30),
                Person(3,"bbb",40),
        };

        ofstream fout("person.dat");
        fout.write((const char*)ps,sizeof(ps));
        fout.close();
        Person* pp=(Person*)malloc(sizeof(Person)*100);
        ifstream fin("person.dat");
        fin.read((char*)pp,sizeof(Person)*100);
        cout<<"共读入字节："<<fin.gcount()<<endl;
        int n=fin.gcount()/sizeof(Person);
        
        for(int i=0;i<n;++i)
                cout<<*(pp+i)<<endl;
        fin.close();
        return 0;    
}
