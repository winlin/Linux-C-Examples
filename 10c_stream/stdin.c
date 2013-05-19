#include <stdio.h>
/*
   stdin:键盘
   stdout：显示器    标准输出是带有缓冲区的
   stderr：显示器    标准错误输出是不带缓冲区的
   stderr 输出不能重定向，比如不能重定向到一个文件中；stdout可以
   这三个文件指针每一个程序都有，他们是文件指针。

   清空缓冲区的条件:
          1.程序运行结束；
          2.输出换行；
          3.等待输入数据；
          4.调用fflush( )；
 */
int main(  )
        {
                fprintf(stdout,"%s\n","hello stdout" );

                int x;
                fscanf(stdin,"%d",&x  );  //scanf( "%d",&x );等价
                printf( "x=%d\n",x );

                fflush(NULL );
                fflush( stdout );
                
                printf( "---------------------------\n" );
                fprintf(stdout,"%s","hello stdout" );
                fprintf( stderr,"%s","hahaha" );
                return 0;

        }
