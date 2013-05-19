#include <stdio.h>

int main(  )
        {
                int a[ 10 ] = {1,2,3,4,5,6,7,8,9,10};
                FILE* file = fopen( "c.txt","w+" );
                fwrite( a,sizeof( int ),10,file );
                fclose( file );

                int b[ 10 ];
                file = fopen( "c.txt","r+" );
                fread( b,sizeof( int ),10,file );
                int i=0;
                for( i=0;i<10;++i )
                        printf( "%d  ",b[ i ] );

                printf( "\n" );
                
                return 0;
                
        }
