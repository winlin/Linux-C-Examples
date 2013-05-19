/*1、计算多项式的值*/
#include <stdio.h>
double my_power( float x,int times  )
        {
                double result=1.0;
                for( int i=1;i<=times;++i )
                        result *=x;
                return result;
        }
int main(  )
        {
                double result;
                double x;
                printf( "please input a number \n" );
                scanf( "%lf",&x);
                result=3*my_power( x, 5)+2*my_power( x,4 )-5*my_power( x,3 )-my_power( x,2 )+7*x-6;

                printf( "the result is %lf\n",result );
                return 0;
                
        }

/*2、用函数实现求个人所得税*/
#include <stdio.h>

float my_tax(float salary,float insure)
        {
        int tax;
        float temp;
        temp=salary-insure-2000;
        if( temp<=0 )
            tax=0.0;
        if( temp<=500 )
            tax=temp*0.05;
        else if( temp<=2000 )
            tax=25+( temp-500 )*0.1;
        else if( temp<=5000 )
            tax=175+( temp-2000 )*0.15;
        else if( temp<=20000 )
            tax=625+( temp-5000 )*0.2;
        else if( temp<=40000 )
            tax=3625+( temp-20000 )*0.25;
        else if( temp<=60000 )
            tax=8625+( temp-40000 )*0.3;
        else if( temp<=80000 )
            tax=14625+( temp-60000 )*0.35;
        else if( temp<=100000 )
            tax=21625+( temp-80000 )*0.4;
        else
            tax=29625+( temp-100000 )*0.45;

        return tax;
        
        }
int main(  )
    {
        float salary;  //工资
        float insure;  //三险一金
        float tax;       //个人所得税
        
        printf( "请输入工资和三险一金的数额\n" );
        scanf( "%f%f",&salary,&insure );
        tax=my_tax( salary,insure );
        printf( "tax=%lf\n",tax );
        return 0;
        
    }

/*3、判断回文字符串*/
#include <stdio.h>
#include <string.h>
int main(  )
        {
                char str[ 100 ];
                printf( "please input a string(less 100 chars )\n" );
                int length=0;
                gets( str);
                length=strlen( str );
                int head=0;
                int rear=length-1;
                while( str[ head ]==str[ rear ]&&head<=rear )
                        {
                                ++head;
                                --rear;
                        }
                if( head>rear )
                        printf( "是回文\n" );
                else
                        printf( "不是回文\n" );
                return 0;
        }

/*4、利用指针判断回文字符串*/
#include <stdio.h>
#include <string.h>
int main(  )
        {
                char str[ 100 ];
                printf( "please input a string(less 100 chars )\n" );
                int length=0;
                gets( str);
                length=strlen( str );
                char *head=&str[ 0 ];
                char *rear=&str[ length-1 ];
                
                while( *head==*rear&&head<=rear )
                        {
                                ++head;
                                --rear;
                        }
                if( head>rear )
                        printf( "是回文\n" );
                else
                        printf( "不是回文\n" );
                return 0;
        }

/*5、使用字典序列找出最大最小字符串*/
#include <stdio.h>
#include <string.h>
int main(  )
        {
                char min_str[ 20 ];
                char max_str[ 20 ];
                char tmp_str[ 20 ];
                short flag=0;
                printf( "请输入字符串，长度为4的字符串为结束\n" );
                while( scanf( "%s",tmp_str )&&strlen( tmp_str )!=4 )
                        {
                                if( !flag )
                                        {
                                                strcpy( min_str,tmp_str );
                                                strcpy( max_str,tmp_str );
                                                flag=1;
                                        }
                                if( strcmp(tmp_str,min_str)<0 )
                                        strcpy( min_str,tmp_str );
                                else if( strcmp( tmp_str,max_str )>0 )
                                        strcpy( max_str,tmp_str );
                        }
                printf( "Smallest Word:%s\n",min_str );
                printf( "Largest Word:%s\n",max_str );
                return 0;
        }

/*6、英文年月日格式化处理*/
#include <stdio.h>
int main(  )
        {
                short int month;
                short int day;
                int year;
                char chr1,chr2;
                printf( "请输入日期(mm/dd/yyyy )\n" );
                scanf( "%hd%c%hd%c%d",&month,&chr1,&day,&chr2,&year );

                char month_ary[ 12 ][ 15 ]=
                        {
                                "January","February","March","April","May","June","July","August","September","October","Novembre","December"
                        };
                
                printf( "You entered date %s %d,%d\n",month_ary[ month-1 ],day,year );

                return 0;
        }
