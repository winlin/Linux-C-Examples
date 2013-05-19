/*3、比较两个年份的早晚*/
#include <stdio.h>

int main(  )
    {
        int a[ 3 ];
        int b[ 3 ];
        
        printf( "请输入第一个日期:( EX:1999-3-18 )\n" );
        for( int i=0;i<3;++i )
            scanf( "%d%*c",&a[ i ] );
         printf( "请输入第二个日期:( EX:1999-3-18 )\n" );
        for( int i=0;i<3;++i )
            scanf( "%d%*c",&b[ i ] );
         
        if( a[ 0 ]<b[ 0 ] )
            printf( "%d-%d-%d更早\n",a[ 0 ],a[ 1 ],a[ 2 ] );
        else if( a[ 0 ]>b[ 0 ] )
            printf( "%d-%d-%d更早\n",b[ 0 ],b[ 1 ],b[ 2 ] );
        else
            {
                if( a[ 1 ]<b[ 1 ] )
                    printf( "%d-%d-%d更早\n",a[ 0 ],a[ 1 ],a[ 2 ] );
                else if( a[ 1 ]>b[ 1 ] )
                    printf( "%d-%d-%d更早\n",b[ 0 ],b[ 1 ],b[ 2 ] );
                else
                    {
                        if( a[ 2 ]<b[ 2 ] )
                            printf( "%d-%d-%d更早\n",a[ 0 ],a[ 1 ],a[ 2 ] );
                        else if( a[ 2 ]>b[ 2 ] )
                            printf( "%d-%d-%d更早\n",b[ 0 ],b[ 1 ],b[ 2 ] );
                        else
                            printf( "两个年份一样\n" );
                    }
            }

        return 0;
        
    }
