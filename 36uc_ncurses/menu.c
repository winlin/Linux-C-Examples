/*
 *使用curses库来设计菜单窗口
 */
#include <curses.h>

int main()
{   
	initscr();
	int y=1;
	double price;
	int number;
	double money;
	double sum=0;
	mvprintw(0,5,"======================MENU===================");
	while(1){
		mvaddstr(y,5,"Price");
		mvaddstr(y,15,"Number");
		mvaddstr(y,25,"Money");
		mvscanw(y,11,"%lf",&price);
		if(price<0){
			break;
		}
			
		mvscanw(y,22,"%d",&number);
		money=number*price;
		mvprintw(y,31,"%.2f",money);
		sum+=money;
		refresh();
		++y;
	}
	move(y,0);
	clrtoeol();
	mvprintw(y,25,"Acconut:%.2f",sum);
	refresh();
	
	getch();
	
	endwin();
	
	return 0;
}
