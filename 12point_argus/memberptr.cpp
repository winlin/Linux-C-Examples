#include <iostream>
#include <cstdio>
using namespace std;
struct Date
{
        int y;     //0是y的成员地址
        int m;     //4是m的成员地址
        int d;     //8是d的成员地址
        void show(  )
                {
                        cout<<y<<'-'<<m<<'-'<<d<<endl;
                }
};
void show( Date*ds,int n,int Date::* p )  //只会打印相对应的成员地址指向的成员
        {
                for( int i=0;i<n;++i )
                        cout<< ds[ i ].*p<<" ";   //cout<<(ds+i)->*p<<"  ";
                cout<<endl;
        }

int main(  )
        {

                int Date::* p=&Date::y;  //取得y的相对地址
                cout<<p<<endl;           //相对地址打印出来就是1
                printf( "p=%d\n",p );

                cout<<main<<endl;        //会打印出1，表示地址存在
                printf( "main=%p\n",main );
                
                Date da[ 5 ]={
                        {2001,3,12},
                        {2006,4,3},
                        {2012,12,4},
                        {2013,1,1},
                        {1990,2,4}
                };
                show(da,5,&Date::y);
                
                //调用成员函数指针  
                void (Date::*pf)(  ) =&Date::show;
                (da[ 0 ].*pf) (  );
                ( da->*pf ) (  );
                
                return 0;  
        }

/* warning: the address of ‘int main()’ will always evaluate as ‘true’ [-Waddress]
*/
