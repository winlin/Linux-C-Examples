#include <iostream>
using namespace std;
/*
template<typename T> class Array;
template<typename T>
ostream& operator<< (ostream& ,const Array<T>& );
*/
template<typename T>
class Array{
    T* data;
    int size;
    int count;
public:
    Array( int n=0 ):size( n ),count( 0 )
        {
                data=new T[ n ];
        }
    ~Array(  )
        {
                delete [  ] data;
        }
    
    bool insert( T x );
    T& operator[  ]( int n );
    friend ostream& operator<< ( ostream& os,Array& a )
	    {
		    for( int i=0;i<a.count;++i )
			    os<<a[ i ]<<" ";
		    return os;
	    }
};

template<typename T>
bool Array<T>::insert( T x )
{
    if( count>=size ){
            T* ptr=new( nothrow ) T[ 2*size ];
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

template<typename T>
T& Array<T>::operator[  ]( int n )
{
    return data[ n ];
}

int main(  )
    {
	    Array<int> a( 20 );
	    a.insert( 10 );
	    a.insert( 20 );
	    cout<<a<<endl;
	    return 0;
    }
