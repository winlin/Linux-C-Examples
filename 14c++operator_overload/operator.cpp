#include <iostream>
using namespace std;

class Emp{
    string name;
    double salary;
public:
    Emp( string iname="",double isalary=0 )
        :name( iname ),salary( isalary ){}
    void show(  ){
        cout<<"name:"<<name<<"  salary="<<salary<<endl;
    }
    friend ostream& operator<<( ostream& os,Emp& e);
    friend istream& operator>>( istream& is,Emp& e);
};
ostream& operator<<( ostream& os,Emp& e ){
    return os<<"name:"<<e.name<<"  Salary="<<e.salary;
    }
istream& operator>>( istream& is,Emp& e ){
    return is>>e.name>>e.salary;
}

int main(  )
    {
        Emp one( "one",2000 );
        //one.show(  );
        cout<<one<<endl; //cout.operator<<( e )<<endl;
        int x=10;
        cout<<x<<endl; //cout.operator<<( x )<<endl;
        cout.operator<<( x ).operator<<( endl );
        Emp two,three;
        cout<<"please intput the name and salary"<<endl;
        cin>>two>>three;
        cout<<"two:"<<two<<endl<<"three"<<three<<endl;
        
        return 0;
    }
