/*读取b.txt文件*/
#include <stdio.h>
int main(  )
        {
                FILE *file = fopen( "b.txt","r" );
                if( file==NULL )
                        {
                                printf( "file open failed\n" );
                                return 1;
                        }
                int x;
                double d;
                char str[ 20 ];
                fscanf( file,"%d%lf%s",&x,&d,str );
                printf( "%d  %lf  %s\n",x,d,str );
                
                fclose( file );
                return 0;
        }

