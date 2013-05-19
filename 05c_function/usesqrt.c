#include <stdio.h>
#include <math.h>
int main(  )
    {
        int input,i;
        printf( "please input an integer\n" );
        scanf( "%d",&input );

        for( i=2;i<=sqrt( input );++i  )
            {
                if( input==2 )
                    {
                        printf( "%d is a prime\n",input );
                        break;
                    }
                if( input%i==0 )
                    {
                        printf( "%d is not a prime\n",input );
                        break;
                    }
            }
        if( i>sqrt( input ) )
            printf( "%d is a prime\n",input );
        return 0;
    }
/*
  gcc -Wall -std=c99 -lm usesqrt.c -o usesqrt
  要使用math头文件需要链接m库，所以要使用“-lm”
 */
