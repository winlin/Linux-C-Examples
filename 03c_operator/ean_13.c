/*分析EAN_13条形码标准*/
#include <stdio.h>
int main(  )
    {
        int code[ 13 ];
        printf( "please input EAN_13 CODE\n" );
        for( int i=0;i<13;++i )
            scanf( "%1d",&code[i] );

        for( int i=0;i<13;++i )
            printf( "%d",code[ i ] );

        if( a[ 0 ]==0&&a[ 1 ]>=0&&a[ 1 ]<=9 )
            printf( "美国/加拿大\n" );
        else if( a[ 0 ]==4&&a[ 1 ]>=5&&a[ 1 ] <=9 )
            printf( "日本\n" );
        //...
        return 0;
            
    }
