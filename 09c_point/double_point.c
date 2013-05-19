/*把一个数字和字母混合的字符串分开输出
   使用双指针
 */
#include <stdio.h>
#include <stdlib.h>
/*
  int str2int( char* str,char** str1 )
        {
                char tmp1[ 10 ];
                int i=0;
                while( *str!='\0' )
                        {
                                if( *str>='0'&&*str<='9')
                                        {
                                                tmp1[ i ]=*str;
                                                ++i;
                                        }
                                else
                                        break;
                                ++str;
                        }
                
                tmp1[ i ]='\0';
                int result=atoi( tmp1 );
                *str1=str;
                return result;
        }
*/
int str2int( const char* str1,const char** str2 )
        {
                int r=0;
                while( *str1>='0'&&*str1<='9' )
                        {
                                r=r*10+*str1-'0';
                                ++str1;
                        }
                *str2=str1;
                 return r;
        }
int main(  )
        {
                char* str="1234abcd"   ;
                int x;
                char* p;
                const char** str1=&p;   //如果没有定义char* p，则*str1代表的对象不存在，编译就会出错

                x=str2int( str,str1 );
                printf( "%d\n",x );
                printf( "%s\n",*str1 );
                
                return 0;
                
                
        }
