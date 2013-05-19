#include <stdio.h>
#include <time.h>
int main(  )
        {
                int i;
                for( i=0;i<100000000;++i );
                clock_t cv=clock(  );  //clock( )返回的是程序运行到该处使用的CPU时间
                printf( "cv=%d\n",cv );
                printf( "cv=%lfs \n",1.0*cv/CLOCKS_PER_SEC );

                time_t cur;
                time( &cur );
                printf( "cur=%d\n",cur );
                printf( "cur=%d\n",cur/( 60*24*365 ) );
                printf( "%s sec since the Epoch\n",asctime( localtime( &cur ) ) );
                
                return 0;
        }
