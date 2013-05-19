#include <stdio.h>
const int y=10; //全局的const是在代码区的，不可以修改
int main(  )
        {
                const volatile int x=10;  //局部的全局变量是在栈中,可以通过指针修改
                int* p=&x;
                *p=100;
                printf( "%d\n",x );
                //  p=&y;
                //*p=100;  //全局变量在代码区不可修改
                
                return 0;
        }

//如果使用GCC进行编译只会出现WARNING；并且使用不使用volatile不影响结果；
//但是如果使用G++编译器,如果不使用volatile那么G++就会进行优化，把x一直当
//成10常量，即使你修改了x的值，打印的时候也不会反映出来。
