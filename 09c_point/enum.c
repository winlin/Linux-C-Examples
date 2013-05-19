#include <stdio.h>
int main(  )
        {
                enum Season{SPRING,SUMMER,AUTUMN,WINTER};
                enum Season s;
                s=SPRING;
                printf( "s=%d\n",s );
                return 0;
        }
/*其中的项SPRING相当于定义的一个常量整数
   可以当作int来使用；
   int x=SUMMER;
   x=SUMMER+100;

 */
