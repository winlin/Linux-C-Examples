#include <iostream>
#include <ctime>
#include <iomanip>
#include "time.h"
using namespace std;

void Time::tick( )
        {
                ++s;
                if( (s%=60)==0 )
                        {
                                ++m;
                                if( (m%=60)==0 )
                                        {
                                                ++h;
                                                if( (h%=24)==0 );
                                        }
                        }
        }

void Time::show(  )
{
        cout<<setfill( '0' )
        <<setw( 2 )<<h<<":"
        <<setw( 2 )<<m<<":"
       <<setw( 2 )<<s<<flush<<'\r';
}

void Time::run(  )
        {
                while( 1 )
                        {
                                tick(  );
                                show(  );
                                time_t cur=time(NULL);
                                while( time(NULL)==cur );
                        }
        }
