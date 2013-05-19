/*约瑟夫问题*/
#include <stdio.h>
#include <stdbool.h>
#define HUMEN    4
int main(  )
        {
                bool  humen[ HUMEN ]={0};
                short int i=0,j=0,count=0;
                for( j=0;j<HUMEN;++j )
                        {
                                while( count<=8 )
                                        {
                                                if( !humen[ i ] )
                                                {
                                                        ++count;
                                                        if( !(count%8) )
                                                        {
                                                           printf( "%d ",i+1 );
                                                           humen[ i ]=1;
                                                           break;
                                                        }
                                                }
                                                ++i;
                                                i %=4;
                                        }
                                count=0;
                                
                        }
                printf( "\n" );
                return 0;
                
        }
