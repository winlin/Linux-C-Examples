#include <iostream>
using namespace std;

class Date{
        int y,m,d;
public:
        Date( int iyear,int imonth,int iday )
                :y( iyear ),m( imonth ),d( iday ){
                cout<<"Date(  ) called"<<endl;
        }
};
class Emp{
        string name;
        Date* birth;
public:
        Emp( string iname,int iyear,int imonth,int iday )
                :name( iname ){
                birth=new Date( iyear,imonth,iday );   //Attention!!!
                cout<<"Emp( ) called"<<endl;
        }
        ~Emp(  ){
                delete birth;
                cout<<"~Emp(  ) called"<<endl;
        }
};

int main(  ){
        Emp  one( "liu",2000,10,30 );
        return 0;
}
/*
  在构造函数里面分配的空间必须是堆里面的，如果是栈里面的话，
  则会在调用构造函数结束后又自动释放，所以，要使用new分配。
 */
