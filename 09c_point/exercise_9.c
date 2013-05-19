/*编写对日期进行排序的通用函数*/
#include <stdio.h>
struct date
{
        int year;
        short int month;
        short int day;
};

int is_year( struct date a,struct date b )     //如果返回值为bool就会产生错误
        {
                return (a.year>b.year?1:( a.year<b.year?-1:0 ));
        }

int is_month( struct date a,struct date b )
        {
                return a.month>b.month?1:( a.month<b.month?-1:0 );
        }
int is_day( struct date a,struct date b )
        {
                return a.day>b.day?1:( a.day<b.day?-1:0 );
        }

void my_sort( struct date* date_ary,int size, int ( *pfun )( struct date a,struct date b ) )
        {
                int i,j;
                for( i=0;i<size;++i )
                        for( j=0;j<size-i-1;++j )
                                {
                                        if( pfun( date_ary[ j ],date_ary[ j+1 ] )>0 )
                                                {
                                                        struct date tmp;tmp=date_ary[ j ];date_ary[ j ]=date_ary[ j+1 ];
                                                        date_ary[ j+1 ]=tmp;
                                                }
                                }
        }
void my_print( const struct date* ary,int size )
        {
                int i;
                for( i=0;i<size;++i )
                        printf( "%d  %hd  %hd\n",ary[ i ].year,ary[ i ].month,ary[ i ].day );
        }

int main(  )
        {
                struct date date_ary[ 5 ];
                int i;
                printf( "     5   \n" );
                for( i=0;i<5;++i )
                        scanf( "%d%hd%hd",&date_ary[ i ].year,&date_ary[ i ].month,&date_ary[ i ].day );

                printf( "       \n" );
                my_sort( date_ary,5,is_year );
                my_print( date_ary,5 );
                printf( "       \n" );
                my_sort( date_ary,5,is_month );
                my_print( date_ary,5 );
                  printf( "       \n" );
                my_sort( date_ary,5,is_day );
                my_print( date_ary,5 );
                
                return 0;
                
        }


/*编写特定的过滤数组的规则*/
#include <stdio.h>
void filter( int* int_ary,int size,int ( *pfun )( int a ) )
        {
                int count=0;  //记录满足条件的整数个数
                int i;
                for(i=0;i<size;++i)
                        if( pfun( int_ary[ i ] )>0 )
                                {
                                        printf( "%d ",int_ary[ i ] );
                                        ++count;
                                }
                printf( "\n满足条件的整数共有%d个\n",count );
                
        }
int positive_int( int a )
        {
                return a>0?1:0;
        }

int main(  )
        {
                int int_ary[ 10 ];
                printf( "请输入10个整数\n" );
                int i;
                for( i=0;i<10;++i )
                        scanf( "%d",&int_ary[ i ] );

                printf( "输出正整数\n" );
                filter( int_ary,10,positive_int );
                        
                return 0;
        }

/*返回一个字符串文件名image000.jpg~~image999.jpg*/
#include <stdio.h>
#include <string.h>

char* file_str( int *value,char *str )
        {
                if( *value==1000 )
                        *value=0;
                
                strcpy( str,"image" );
                sprintf( &str[ 5 ],"%03d",*value );
                (*value)++;
                return str;  
        }

int main(  )
        {
                int value=0;
                char str[ 13 ];
                char *pstr=NULL;
                for( int i=0;i<1100;++i)
                        {
                                pstr=file_str( &value,str );
                                printf( "%s\n",pstr );
                        }
                
                return 0;
        }
