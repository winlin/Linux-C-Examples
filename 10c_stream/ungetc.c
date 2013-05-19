#include <stdio.h>
/*从a.txt文件里面分离出来double数据
 */
int main(  )
        {
                FILE* file = fopen( "a.txt","r" );
                char ch;
                while( ( ch=getc( file ) )!=EOF )
                        {
                                if( ch>='0'&&ch<='9' )
                                        {
                                                ungetc( ch,file );
                                                double d;
                                                fscanf( file,"%lf",&d );
                                                printf( "%lf   ",d );
                                        }
                                else
                                        continue;
                        }
                return 0;
                
        }
