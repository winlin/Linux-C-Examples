/*对齐和补齐*/
#include <stdio.h>
typedef struct
{
 short a;
 long b;
}example_1;

typedef struct
{
 char c;
 example_1  struc;
 short e;
}example_2;

int main(  )
 {
     example_1 struc1;
     example_2 struc2;
     printf( "sizeof( long )=%ld\n",sizeof( long ) );
     printf( "sizeof( int )=%ld\n",sizeof( int ) );
     printf( "sizeof( char )=%ld\n",sizeof( char ) );
     printf( "sizeof( short )=%ld\n",sizeof( short ) );
     
     printf( "\nsizeof( example_1 )=%ld\n",sizeof( example_1 ) );
     printf( "&struc1.a=%p\n",&struc1.a );
     printf( "&struc1.b=%p\n",&struc1.b );
     
     printf( "\nsizeof( example_2 )=%ld\n",sizeof( example_2 ) );
     printf( "&struc2.c=%p\n",&struc2.c );
     printf( "&struc2.struc=%p\n",&struc2.struc );
     printf( "&struc2.struc.a=%p\n",&struc2.struc.a );
     printf( "&struc2.struc.b=%p\n",&struc2.struc.b );
     printf( "&struc2.e=%p\n",&struc2.e );
     
     return 0;
     
 }    
