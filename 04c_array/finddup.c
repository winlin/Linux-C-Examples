/*判断一个数字当中是否有重复出现的数字*/
#include <stdio.h>
#include <stdbool.h>

int main(  )
    {
        int num_array[ 10 ]={0};
        int input_num;
                
        printf( "Pleae input an integer\n" );
        scanf( "%d",&input_num );

       while( input_num )
           {
              ++num_array[ input_num%10 ]; 
              input_num /= 10;
           }
       
       for( int i=0;i<10;++i )
           {
               if( num_array[ i ]>=1 )
                   {
                       printf( "%d重复出现%d次\n",i,num_array[ i ] );
                   }
           }
       
       return 0;
       
    }
