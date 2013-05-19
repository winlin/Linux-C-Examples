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

/*取得短整型的高字节和低字节，取得一个int的高2字节和低2字节*/
#include <stdio.h>

#define HIBYTE( number ) { (number>>8)}
#define LOBYTE( number ) { ( number&0x00ff) }

#define HIBYTE2( number ) { (number>>16)}
#define LOBTYE2( number ) { ( number&0x0000ffff)}

int main(  )
        {
                short int shor;
                printf( "please input a short inetger \n" );
                scanf( "%hi",&shor );
                short int hi_value=HIBYTE( shor );
                printf( "high byte value=%0x\n",hi_value );
                short int low_value=LOBYTE( shor );
                printf( "low byte value=%0x\n",low_value );

                int inter;
                printf( "please input a inetger \n" );
                scanf( "%i",&inter );
                short int hi_2_value=HIBYTE2( inter );
                printf( "high 2 bytes value=%0x\n",hi_2_value );
                short int low_2_value=LOBTYE2( inter );
                printf( "low 2 bytes value=%0x\n",low_2_value );
                
                return 0;
        }
