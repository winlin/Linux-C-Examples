#include <iostream>
using namespace std;

class Array{
    int* data;
    int size;
    int count;
public:
    Array( int n=0 ):size( n ),count( 0 )
        {
                data=new int[ n ];
        }
    ~Array(  )
        {
                delete [  ] data;
        }
    
    bool insert( int x );
    int& operator[  ]( int n );
    friend ostream& operator<<( ostream& os,Array& a );
};

bool Array::insert( int x )
{
    if( count>=size ){
            int* ptr=new( nothrow ) int[ 2*size ];
            if( !ptr ){
                    cerr<<"ERROR:Allocate";
                    return 0;
            }
            for( int i=0;i<size;++i ){
                    ptr[ i ]=data[ i ];
            }
            delete [  ] data;
            data=ptr;
            size*=2;
        }
    data[ count ]=x;
    ++count;
    return 1;
}

int& Array::operator[  ]( int n )
{
    return data[ n ];
}

ostream& operator<<( ostream& os,Array& a )
{
    for( int i=0;i<a.count;++i )
        os<<a[ i ]<<" ";
    return os;
}

int main(  )
    {
        Array a( 20 );
        a.insert( 10 );
        a.insert( 20 );
        cout<<a<<endl;
        return 0;
    }
