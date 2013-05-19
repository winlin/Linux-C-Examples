#include <iostream>
using namespace std;
class A{
    int x;
    int y;
public:
    void m1(  ){cout<<x<<endl;}
    void m2(  ){cout<<y<<endl;}
};

int main(  )
    {
        cout<<"sizeof( A )="<<sizeof( A )<<endl;
        A a;
        a.m1(  );
        return 0;
    }

/*sizeof( A )的大小仅仅只包含非static的数据成员的大小*/
