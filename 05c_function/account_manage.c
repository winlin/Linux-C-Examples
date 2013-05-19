/*帐薄管理*/
#include <stdio.h>
#include <stdlib.h>
int main(  )
        {
                double menoy=0.0;
                int choose;
                double stroe;
                
                printf( "请输入功能选项\n" );
        menu:
                printf( "---------------MENU-----------------\n" );
                printf( "1.存钱\n" );
                printf( "2.取钱\n" );
                printf( "3.清零\n" );
                printf( "4.查看余额\n" );
                printf( "5.退出系统\n" );

                scanf( "%d",&choose );
                switch( choose )
                        {
                        case 1:
                                printf( "请输入存款金额\n" );
                                scanf( "%lf",&stroe );
                                menoy+=stroe;
                                break;
                        case 2:
                                printf( "请输入取款金额\n" );
                                scanf( "%lf",&stroe );
                                menoy-=stroe;
                                break;
                        case 4:
                                printf( "账户余额%.2lf\n",menoy );
                                break;
                        case 3:
                                menoy=0.0;
                                printf( "已清空\n" );
                                break;
                        case 5:
                                exit( 0 );
                        default:
                                printf( "输入的选项无效，请重新输入\n" );
                                break;
                                
                        }
                goto menu;
                return 0;
        }
