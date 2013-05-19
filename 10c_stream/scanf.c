#include <stdio.h>

int main(  )
        {
                int x,y;
                scanf( "%3d%5d",&x,&y );
                printf( "x=%d, y=%d\n",x,y );

                scanf( "%*d%d",&x );
                printf( "x=%d\n",x );

                char str1[ 10 ];
                char str2[ 10 ];
                scanf( "%*[ ^\n ]" );
                scanf( "%*c" );

                scanf( "%[ a-z ]%[ ^a-z^\n ]",str1,str2 );
                printf( "str1=%s,str2=%s\n",str1,str2 );
                return 0;
                
        }
