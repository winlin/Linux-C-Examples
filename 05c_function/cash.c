/*打印利率的表格*/
/*
Year       6%        7%        8%        9%       10% 
   0   106.00    107.00    108.00    109.00    110.00  
   1    112.36    114.49    116.64    118.81    121.00  
   2   119.10    122.50    125.97    129.50    133.10  
   3   126.25    131.08    136.05    141.16    146.41  
   4   133.82    140.26    146.93    153.86    161.05 
  
 */
#include <stdio.h>

int main(  )
    {
        float money_ary[ 5 ];
        float rate;
        int rate_int;
        int years;
        printf( "input the rate and years(如果利率为%%6,则输入6 )\n" );
        scanf( "%d%d",&rate_int,&years );
        rate=rate_int/100.0;
        
        int i,j;
        
        printf( "Year" );
        for( i=0;i<5;++i )
            printf( "%8d%% ",rate_int+i );
        printf( "\n" );
        
        for(i=0;i<years;++i)
            {
                printf( "%4d ",i );
                for( j=0;j<5;++j )
                    {
                        if( i==0 )
                            {
                                money_ary[ j ]=100*( 1+rate+j/100.0 );
                            }
                        else
                            {
                                money_ary[ j ]=money_ary[ j ]*( 1+rate+j/100.0 );
                            }
                         printf( "%8.2f  ",money_ary[ j ] );
                    }
                printf( "\n" );
            }

        return 0;
        
    }
