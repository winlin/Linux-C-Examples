/*
 *读取键盘输入
 */
#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();
	while(1){
		int ch=mvgetch(8,8);
		if(ch=='q')
			break;
		
		mvaddch(0,0,ch);
		mvwaddch(stdscr,0,COLS-1,ch);
		refresh();
	}
	endwin();
	return 0;
}
