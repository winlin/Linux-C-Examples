/*定义函数数组*/
/*函数数组的成员必须是同一种类型的函数，即形参相同，但是函数名不同，
  返回值不同会产生警告，但是可以通过编译运行*/
#include <stdio.h>
int fun1( int a,int b )
        {
                return a+b;
        }
float fun2(  int a,int b)
        {
                return a-b;
        }

int main(  )
        {
                int  (* fun_arry[ 2 ] )(int,int);
                fun_arry[ 0 ]=fun1;
                fun_arry[ 1 ]=fun2;
                
                int a=5,b=8;
                printf( "%d\n",fun_arry[ 0 ]( a,b ));
                printf( "%d\n",fun_arry[ 1 ]( a,b));
                return 0;
                
        }
