#include <stdio.h>
#include <stdlib.h>
/*sprintf可以把int/float等任何数据类型转换成，你想要的字符串形式*/
int main(  )
        {
                int x=10;
                char* s=( char* )malloc( 10 );
                sprintf( s,"x=%d",x );
                printf( "s: %s\n",s );

               struct Date
               {
                               int y,m,d;
               };

               struct Date d={2011,12,4};
               char date[ 20 ];
               sprintf( date,"%04d-%02d-%02d",d.y,d.m,d.d );
               printf( "date:%s\n",date );
               
                free( s );
                
                return 0;
                
        }
