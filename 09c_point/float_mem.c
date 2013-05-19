#include <stdio.h>
#include <stdbool.h>
union float_mem
{
        float  ff;
        bool bb[32];
};

int main()
        {
                union float_mem test;
                printf("please input a float\n");
                scanf("%f",&test.ff);

                for(int i=0;i<32;++i)
                        {
                                printf( "%b",test.bb[ i ] );
                        }
                printf( "\n" );
                return 0;
                
        }

        
