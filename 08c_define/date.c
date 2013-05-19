#include <stdio.h>

#define ISLEAP( y )         ( ( y )%4==0&&( y )%100!=0||( y )%400==0 )
#define ISSMALL( m )     ( ( m )==4||( m )==6||( m )==9||( m )==11 )
#define NORMAL( m )     ( ISSMALL( m )?30:31 )
#define DAY( y,m )          ( ( m )==2?28+ISLEAP( y ):NORMAL( m ) )
#define IN( x,from,to )   ( ( x )>=from&&( x )<=to )
#define VALID( y,m,d )    ( y>=1600&&IN( m,1,12 )&&IN( d,1,DAY(y,m))?1:0 )

int main(  )
        {
                if( VALID( 2011,2,35 ) )
                        printf( "Yes\n" );
                else
                        printf( "No\n" );
                
                return 0;
        }
