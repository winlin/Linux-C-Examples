#include <iostream>
#include <cstdlib>
using namespace std;

class F{
    int n,d;
public:
    F( int nn=0,int bb=1 ):n( nn ),d( bb )
        {if(!d){cerr<<"denominator can't be 0"<<endl;exit( -1 );}}
    
    friend ostream& operator<<( ostream& os,F& f);
    friend istream& operator>>( istream& is,F& f);
    friend const F operator+( const F& f1,const F& f2 );
    friend const F operator-( const F& f1,const F& f2 );
};

ostream& operator<<( ostream& os,F& f ){
    if( f.d<0 )
        return os<<-f.n<<"/"<<-f.d;
    else if( f.n==0 )
        return os<<"0";
    return os<<f.n<<"/"<<f.d;
}

istream& operator>>( istream& is,F& f ){
    return is>>f.n>>f.d;
}

const F operator+( const F& f1,const F& f2 ){
    int nn,dd;
    nn=f1.n*f2.d+f2.n*f1.d;
    dd=f1.d*f2.d;
    if(!nn){nn=0;dd=0;return F();}
    /*reduction of fraction*/
    for( int i=2;i<=abs(dd)&&i<=abs(nn);)
        {
            if( !(dd%i)&&!(nn%i) )
            {dd=dd/i;nn=nn/i;}
            else
                ++i;
        }
    return F( nn,dd );
}

const F operator-( const F& f1,const F& f2 ){
    int nn,dd;
    nn=f1.n*f2.d-f2.n*f1.d;
    dd=f1.d*f2.d;
    if(!nn){nn=0;dd=0;return F();}
    /*reduction of fraction*/
    for( int i=2;i<=abs(dd)&&i<=abs(nn);)
        {
            if( !(dd%i)&&!(nn%i) )
            {dd=dd/i;nn=nn/i;}
            else
                ++i;
        }
    return F( nn,dd );
}


int main(  )
    {
        F one( 1,8 );
        cout<<"one="<<one<<endl;
        F two;
        cout<<"input two interger"<<endl;
        cin>>two;
        cout<<"two="<<two<<endl;
        F three=one+two;
        cout<<"three=one+two:"<<three<<endl;
        F four=two-one;
        cout<<"four=two-one:"<<four<<endl;
        return 0;
    }
