/*Single类和空结构体其大小都是0，
 但是在打印的时候却显视的为1
*/
#include <iostream>
#include <cstdio>
using namespace std;

class Single{
private:
    Single( ){}
    Single( const Single& e){}
public:
    static Single s;
    static Single& getInstance( )
        {
            return s;
        }
};
Single Single::s;
struct b{
};
struct c{
    int a;
};

int main( )
    {
        Single& s1=Single::getInstance( );
        cout<<"sizeof( s1)="<<sizeof( s1)<<"   "<<sizeof( Single::s )<<endl;
        printf("%d\n",sizeof(s1));
        cout<<"sizeof( b)="<<sizeof( b)<<endl;
        printf( "%d\n",sizeof(b));
        cout<<"sizeof( c)="<<sizeof( c)<<endl;
        return 0;
    }

