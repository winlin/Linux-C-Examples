#include <iostream>
using namespace std;

class Emp{
        string name;
        int age;
public:
        Emp( string iname,int iage )
                :name( iname ),age( iage ){
                cout<<"Emp( ) called"<<endl;
        }
        Emp( const Emp& other ){
                name=other.name;
                age=other.age;
                cout<<"Emp( const Emp& ) called"<<endl;
        }
        ~Emp(  ){
                cout<<"~Emp( ) called"<<endl;
        }
        
};

int main(  )
        {
                Emp one( "liu",23 );
                Emp two=one;
                return 0;
        }
