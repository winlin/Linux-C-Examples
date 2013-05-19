#include <stdio.h>
/*
  getc( )
  putc(  )
  二者都是宏函数
  _IO_getc(  );
  _IO_putc(  );
 */
int main(  )
        {
                FILE* file=fopen( "file.c","r" );
                if( file==NULL )
                        return -1;
                
                char ch;
                while( ( ch=getc( file ) )!=EOF )
                {
                        printf( "%c",ch );
                }

                fclose( file );
                return 0;
        }
