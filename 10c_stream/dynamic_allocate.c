/*对于动态分配的内存空间要注意保存其返回的指针地址，并检查返回值
  最后要记住释放内存，防止产生悬空指针*/
#include <stdio.h>
#include <stdlib.h>

int main(  )
        {
                int *p1=NULL,*p2=NULL;
                p1=( int* )malloc( 5*sizeof( int ) );
                p2=( int* )calloc( 5,sizeof( int ) );

                if( !p1||!p2 )
                        exit( -1 );
                 
                for( int i=0;i<5;++i )       //malloc不会初始化为0
                        printf( "%d ",p1[ i ] );
                printf( "\n" );
                for( int i=0;i<5;++i )    //calloc会初始化为0
                        printf( "%d ",p2[ i ] );
                printf( "\n" );

                int *rp=realloc( p1,2*5*sizeof( int ) );
                if( rp==NULL )
                {/*重新分配内存失败*/}

                for( int i=0;i<10;++i )
                        printf( "%d ",rp[ i ]);  //注意realloc可能会改变内存块的位置，所以要使用rp而不是p1！！！
                //注意要回收内存
                free( rp );
                free( p2 );
                p1=p2=rp=NULL;   //防止产生悬空指针
                
                printf( "\n" );
                return 0;
                
        }
