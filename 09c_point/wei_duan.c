#include <stdio.h>
int main(  )
        {
                typedef unsigned int UINT;
                struct Ct1
                        {
                                UINT  INT:1;
                                UINT  C1:1;
                                UINT  C2:1;
                                UINT  C3:1;
                                UINT RES:1;
                };

                struct Ct1 c;
                printf( "sizeof( struct Ct1 )=%ld\n",sizeof( c ) );
                return 0;
                
        }
//结果为4B，结构体最小占用4B
