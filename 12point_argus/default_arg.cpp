#include <iostream>
using namespace std;
/*
void print( int* a,int b )
        {
                for( int i=0;i<b;++i )
                        cout<<a[ i ]<<" ";
                cout<<endl;
        }
void print( int*a ,int b,char c)
        {
                for( int i=0;i<b;++i )
                        cout<<a[ i ]<<c;
                cout<<"\b";
                cout.flush(  );
                cout<<endl;
        }
*/
/*默认参数*/
void print( int* a,int b,char c=' ' )
        {
                for( int i=0;i<b-1;++i )
                        cout<<a[ i ]<<c;
                cout<<a[ b-1 ]<<endl;
        }
int main(  )
        {
                int a[ 10 ]={1,2,3,4,5,6,7,8,9,10};
                // print( a,10 );
                
                char c=',';
                print( a,10,c );
                return 0;
                
        }
