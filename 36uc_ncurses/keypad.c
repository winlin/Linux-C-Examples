/*
 *使用功能键
 *同时要注意清屏工作
 *查看功能键，使用 man getch
 */
#include <curses.h>

int main()
{   
	initscr();
	keypad(stdscr,TRUE);   //打开功能键
	curs_set(0);
	noecho();             //不允许回显
	int y=LINES/2-1;
	int x=COLS/2-1;
	char mc='@';
	
	while(1){
		mvaddch(y,x,mc);
		refresh();
		int ch=getch();
		if(ch==27)
			break;
		mvaddch(y,x,' ');  //清除屏幕
		//clear();             //有大量数据的时候使用
		
		if(ch==27)
			break;
		switch(ch){
		case KEY_UP:
			if(--y<0)
				y=LINES-1;
			break;
		case KEY_DOWN:
			if(++y==LINES)
				y=0;
			break;
		case KEY_LEFT:
			if(--x<0)
				x=COLS-1;
			break;
		case KEY_RIGHT:
			if(++x==COLS)
				x=0;
			break;
		default:
			continue;
		}
	}
	endwin();
	return 0;
}
