/*4个字节构成一个整数*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINK( b1,b2,b3,b4 ){strcat( tmp,b1 );strcat( tmp,b2 );\
                strcat( tmp,b3 );strcat( tmp,b4 );}

int main(  )
        {
                char tmp[ 20 ];
                //tmp[ 0 ]='\0';
                printf( "请输入4个2位数的整数，中间用空格隔开\n" );
                char cc0[ 2 ],cc1[ 2 ],cc2[ 2 ],cc3[ 2 ];
                scanf( "%s %s %s %s",cc0,cc1,cc2,cc3 );
                LINK(cc0,cc1,cc2,cc3);
                int value=atoi( tmp );
                printf( "组合的整数为 :%d\n",value );

                return 0;
        }
