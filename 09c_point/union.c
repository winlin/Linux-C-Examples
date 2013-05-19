#include <stdio.h>
union U1
{
        double dd;
        char cc[ 8 ];
};

int main(  )
        {
                union U1 uu;
                uu.dd=3.14;
                for( int i=0;i<8;++i )
                        printf( "%x ",( unsigned char )uu.cc[ i ] );
                printf( "\n" );
                return 0;
        }
