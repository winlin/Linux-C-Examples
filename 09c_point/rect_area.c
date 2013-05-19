#include <stdio.h>
struct Point
{
        int x;
        int y;
};
struct Rect
{
        struct Point p1;
        struct Point p2;
};

int main(  )
        {
                struct Rect rect_one;
                rect_one.p1.x=3;
                rect_one.p1.y=3;
                rect_one.p2.x=5;
                rect_one.p2.y=5;

                printf( "the area of rect is %d\n",(rect_one.p2.x-rect_one.p1.x)*( rect_one.p2.y-rect_one.p1.y ) );
                return 0;
                
        }

        
