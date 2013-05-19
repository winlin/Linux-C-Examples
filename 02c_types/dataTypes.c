#include <stdio.h>

int main(  )
    {
        int a=10;
        printf( "sizeof( a=100 )=%d\n",sizeof( a=100 ) );
        printf( "sizeof( 3.5 )=%d\n",sizeof( 3.5 ) );      //3.5被看成double
        printf( "a=%d\n",a );
        return 0;
    }
