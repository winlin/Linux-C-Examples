#include <stdio.h>
const char* my_strcpy( char *dest,const char *src )
        {
                if( dest==src )
                        return src;
                if( dest==NULL||src==NULL )
                        return NULL;
                while( *src!='\0' )
                        {
                                *dest++=*src++;
                        }
                
                //while( *str1++=*str2++ );
                
                return dest;
        }

void my_strcat( char *str1,char *str2 )
        {
                while( *str1++ );
                --str1;
                while( *str1++=*str2++ );
                
        }

int main(  )
        {
                char str1[ 10 ]="abcdef";
                char str2[ 10 ]="12345";
                my_strcpy( str2,str1 );
                puts( str1 );
                return 0;
        }
