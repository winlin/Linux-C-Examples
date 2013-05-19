/*
 *创建一个新的窗口
 */
#include <curses.h>

int main()
{
	initscr();
	
	WINDOW* w1=newwin(5,10,4,4);
	//subwin使用屏幕坐标
	WINDOW* w2=subwin(stdscr,12,40,1,15);
	//derwin使用相对坐标
	WINDOW* w3=derwin(w2,3,20,3,5);

	box(w1,0,0);
	box(w2,0,0);
	box(w3,0,0);

//先刷整个窗口
	refresh();
	//再刷新每个特定的窗口
	wrefresh(w1);
	wrefresh(w2);
	wrefresh(w3);

	char name[20]={0};
	mvwprintw(w1,2,1,"Name");
	mvwgetnstr(w1,2,5,name,sizeof(name));
	curs_set(0);
	mvwprintw(w3,1,1,"Welocme %s!",name);
	wrefresh(w3);
	
	getch();
	//先删除子窗口
	delwin(w3);
	delwin(w2);
	delwin(w1);
	
	endwin();
	
	return 0;
}
