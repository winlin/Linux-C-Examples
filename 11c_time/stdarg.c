/*在C语言中要找出最大的字符，我们可以按照寻找最大的int值一样，没有必要
 特意写一个char的比较函数*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int max( int cnt, ... )
        {
                //必须要知道可变长参数的个数
                /*1.声明一个va_list类型的变量，用来保存参数*/
                va_list v;
                /*2.将所有的参数保存到va_lsit变量里面*/
                va_start( v,cnt );
                /*3.从va_list变量里面取出每个参数，进行处理*/
                int mv=va_arg( v,int );

                int i,j;
                for( i=1;i<cnt;++i )
                        {
                                j=va_arg( v,int );
                                if(j>mv)
                                        mv=j;
                        }
                /*4.释放va_list*/
                va_end( v );
                return mv;
        }

char* strmax( int cnt,... )
        {
                va_list v;
                va_start( v,cnt );
                
               char* maxp=va_arg( v, char* ) ;
                int i;
                char* tmpp;
                for( i=1;i<cnt;++i )
                        {
                                tmpp=va_arg( v,char* );
                                if(strcmp( tmpp,maxp ))
                                        maxp=tmpp;
                        }
                va_end( v );
                return maxp;
        }
int main(  )
        {
                printf( "%d\n",max(4,100,200,300,400));
                printf( "%c\n",max(3,'A','b','c'));    //完全可以把字符当作int来处理，即根据ASCII码进行转化
                printf( "%s\n",strmax( 3,"abc","bcd","efg" ) );
                
                return 0;
        }
