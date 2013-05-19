/*3、万年历
  输入年份和月份，打印该年该月的月历
 */
#include <stdio.h>
#include <stdbool.h>

int main(  )
    {
        int year;
        int month;
        int m_month[ 12 ]={31,28,31,30,31,30,31,31,30,31,30,31};
        printf( "请输入年份和月份\n" );
        scanf( "%d%d",&year,&month );

        short int week_day;
        bool is_leap_year=0;
        long sum=0;
        
        is_leap_year= (year%400==0||(year%4==0&&year%100!=0));
        if( is_leap_year )
            m_month[ 1 ]=29;

        sum = (year*365 + year/4 -year/100 +year/400);
        for( int i=0;i<month-1;++i )
            sum+=m_month[ i ];
        week_day=sum%7;
        //printf( "第一天为:%d\n",week_day );

        bool is_blank=0;  //用于在日历第一行输出空格
        short int count=0;  //用于累计日历一行输出的日期数，满7回车
        printf( "日  一  二  三  四  五  六\n" );

        for( int i=1;i<=m_month[ month-1 ];  )
            {
                if( !is_blank )      //在第一行输出空格
                    {
                        for( int j=1;j<=week_day;++j )
                            printf( "    " );
                        is_blank=1;
                    }
                if( i<=7-week_day )   //在第一行输出日期，并回车
                       {
                           for( int j=1;j<=7-week_day;++j )
                           {
                               printf( "%2d  ",i );
                               ++i;
                           }
                       }
                else                      //其他行输出日期
                   {
                       printf( "%2d  ",i );
                       ++count;
                       ++i;
                   }
               
                if( count%7==0 )    //其他行满7输出换行符
                    {
                        printf( "\n" );
                        count=0;
                    }
                    
            }
        
        printf( "\n" );
        return 0;
    }
