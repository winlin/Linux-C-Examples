#include <ncurses.h>
#include <time.h>

int main()
{
	initscr();
	box(stdscr,0,0);
	curs_set(0);
	for(;;){
		time_t now = time(NULL)-8*3600-5*60;//调整错误时间
		struct tm* p = localtime(&now);
		char buf[100];
		int len=strftime(buf,sizeof(buf),"%F %w %T", p);
		mvprintw(LINES/2-1,(COLS-len)/2-1,"%s",buf);
		refresh();
		sleep(1);
	}
	endwin();
}

