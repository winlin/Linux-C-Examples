#ifndef MY_TIME_H
#define MY_TIME_H
/*
  时间类
 */
class Time
{
        int h,m,s;
public:
        Time( int h=0,int m=0,int s=0 ):h( h ),m( m ),s( s ){}
        void tick(  );
        void show(  );
        void run(  );
};

#endif
/*
  在类的定义和实现分开以后，我们就可以编译:
  g++ -c time.cpp -o time.o
  然后在使用该类的文件test.cpp里面
 #include "time.h"
 在编译的时候:
 g++ test.cpp time.o -o test
 */
