/*
 *获取字符串
 */
#include <curses.h>

int main()
{   
	initscr();
	keypad(stdscr,TRUE);
	int y=1;
	while(1){
		char line[100]={0};
		move(0,0);
		clrtoeol(); //清空第一行输入部分
		
		mvgetnstr(0,0,line,sizeof(line));
		mvprintw(y++,0,"%-*s",COLS,line);   //输出特定长度的字符串
		refresh();
		if(y==LINES)
			y=1;
	}
	endwin();
	
	return 0;
}
