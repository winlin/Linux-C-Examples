#include <stdio.h>

int main(  )
        {
                FILE *file = fopen( "a.txt","w" );
                if( file==NULL )
                        {
                                printf( "file open failed\n" );
                                return 1;
                        }
                fprintf( file,"%s\n","Hello file" );
                fclose( file );
                return 0;
                
        }
