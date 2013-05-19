/*打印一块内存区域的对应的16进制的内容*/
#include <stdio.h>
void showbyte( void* addr,int bytes )   //传递一块内存的起始地址和字节长度
        {
                while( bytes-->0 )
                        printf( "%02x ",*( unsigned char*)addr++ );   //%02x每1B字节打印两个字符，并且如果为0则打印0
                                                                                                //%2x表示若为0则打印空格
                printf( "\n" );
        }

int main(  )
        {
                int a=0x12345678;
                showbyte( &a,sizeof( int ) );
                return 0;
        }
