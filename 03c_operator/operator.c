/*倒序输出一个3位的int数据*/
#include <stdio.h>
int main(  )
    {
        printf( "input 3-length integer\n" );
        int mInt;
        scanf( "%d",&mInt );
        int i,j,k;
        i=mInt/100;
        j=mInt%100/10;
        k=mInt%10;
        printf( "%d%d%d\n",k,j,i );
        return 0;
        
    }
