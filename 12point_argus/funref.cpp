#include<iostream>
using namespace std;

void fa( int& x )
        {
                cout<<&x<<endl;
                ++x;
        }
void my_swap( int&  a,int& b )
        {
                int tmp=a;
                a=b;
                b=tmp;
        }

int& fc( int& r )
        {
                --r;
                return r;
        }

int ffc(int& x)
        {
                x++;
                return x;
        }

int main()
        {
                int x=10;
                int y=20;
                fa( x );
                cout<<&x<<endl;
                cout<<x<<endl;
                cout<<"x="<<x<<"   y="<<y<<endl;
                my_swap(x,y);
                cout<<"x="<<x<<"   y="<<y<<endl;
                int& ry=fc( y );
                cout<<"y="<<ry<<endl;

                int a=ffc( x );
                a++;
                cout<<"x="<<x<<endl;
                //int& rx=ffc( x );  //ERROR:rx指向一个临时变量
                int b=fa( x );   //int b=x;
                
                return 0;
                
        }
