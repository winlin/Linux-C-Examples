#include <stdio.h>
/*
 文件打开方式w+;r+是有区别的，w+会先建立该文件再读写
 r+不会新建一个文件，如果文件不存在则返回错误

另外，有些文本编辑器会在文件的末尾添加EOF文件结束符，所以，当你
从文件的末尾作为偏移基点时，要考虑到EOF占用一个文件指针位。
 */

int main(  )
        {
                FILE* file = fopen( "d.txt","r+" );
                if( file==NULL )
                        {
                                printf( "can't open file d.txt\n" );
                                return -1;
                        }
                putc( '1',file );

                fseek( file,3,SEEK_SET );
                putc( '4',file );
                
                fclose( file );
                return 0;
        }
