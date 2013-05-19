/*
 *利用curses库，显示时钟
 */
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{   
	initscr();
	box(stdscr,0,0);
	curs_set(0);
	
	start_color();//启用颜色
	init_pair(1,);
	bkgd(COLOR_PAIR);
	
	while(1){
		time_t now=time(NULL);
		struct tm* p=localtime(&now);
		char buf[100];
		int len=strftime(buf,sizeof(buf),"%F %w %T",p);
		mvprintw(LINES/2-1,(COLS-len)/2-1,"%s",buf);
		sleep(1);
		refresh();
	}
	return 0;
}
