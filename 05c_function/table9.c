/*九宫格*/
#include <stdio.h>
#include <stdbool.h>
#define LINE 3

int main(  )
        {
                int i,j;
                int table[ LINE ][ LINE ];  //表格
                int max=LINE;
                int x=0;  //表示行号
                int y=max/2;  //表示列号
                bool full[ LINE][ LINE ];
                for(i=0;i<max;++i)
                        for( j=0;j<max;++j )
                                full[ i ][ j ]=0;
               
                for( i=1;i<=max*max;++i )
                        {
                                table[ x ][ y ]=i;
                                full[ x ][ y ]=1;
                                
                                --x;
                                ++y;
                                if( x<0&&y<=max-1 )   //行越界
                                        x=max-1;
                                if( y>max-1&&x>=0 )   //列越界
                                        y=0;
                                if( (x<0&&y>max-1)||full[ x ][ y ] )  //行列都越界或已放元素
                                        {
                                                x+=2;
                                                --y;
                                        }
                        }

                for( i=0;i<max;++i)
                        {
                                for( j=0;j<max;++j )
                                        printf( "%4d",table[ i ][ j ] );
                                printf( "\n" );
                        }
                return 0;
        }
