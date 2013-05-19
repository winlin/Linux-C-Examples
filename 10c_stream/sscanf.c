#include <stdio.h>

int main(  )
        {
                char date[  ]="2011-2-14";
                int year,month,day;
                sscanf( date,"%d-%d-%d",&year,&month,&day );
                printf( "%d %d %d\n",year,month,day );
                return 0;
                        
        }
