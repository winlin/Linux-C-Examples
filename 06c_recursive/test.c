#include <stdio.h>
int main(  )
        {
                char  int_ary[ 3 ];
                for( int i=0;i<3;++i )
                        {
                                scanf( "%c",&int_ary[ i ] );
                                scanf( "%*c" );
                        }

                scanf( "%*[ ^\n ]" );
                
                char a;
                scanf( "%c",&a );
                printf( "\n%c",a );
                return 0;
                
        }
