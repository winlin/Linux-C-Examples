/*汉诺塔*/
#include <stdio.h>
void han_nuo( int n,char sur,char tmp,char dest )
        {
              if( n==1 )
                      printf( "把第%d个盘子从%c---->%c\n",n,sur,dest );
              else
                      {
                              han_nuo( n-1,sur,dest,tmp );
                              printf( "把第%d个盘子从%c---->%c\n",n,sur,dest );
                              han_nuo( n-1,tmp,sur,dest );
                      }
        }

int main(  )
        {
                int n;
                printf( "请输入盘子的数量\n" );
                scanf( "%d",&n );
                han_nuo( n,'A','B','C' );
                return 0;
        }
