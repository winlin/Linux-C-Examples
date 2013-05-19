#include <ncurses.h>
#include <time.h>

int main()
{
	initscr();
	curs_set(0);
	start_color();
	attron(A_STANDOUT);
	init_pair(1,COLOR_RED,COLOR_WHITE);
//	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
//	int i, j;
//	for(i=0; i<LINES; i++)// mvhline(i,0,' ',COLS);
//		for(j=0; j<COLS; j++)
//			mvaddch(i,j,'.'|COLOR_PAIR(1)|A_BOLD);
//	attroff(COLOR_PAIR(1));
	box(stdscr,0,0);
//	attroff(A_STANDOUT);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_GREEN,COLOR_BLUE);
	for(;;){
		time_t now = time(NULL)-8*3600-5*60;//调整错误时间
		struct tm* p = localtime(&now);
		char date[100], week[20], stime[50];
		int nd, nw, nt;
		int row = LINES/2-1;
		nd=strftime(date,sizeof(date),"%F", p);
		nw=strftime(week,sizeof(week),"星期%w", p);
		nt=strftime(stime,sizeof(stime),"%T", p);
		attron(COLOR_PAIR(2)|A_BOLD);
		mvaddstr(row-1,(COLS-nd)/2-1,date);
		attroff(COLOR_PAIR(2)|A_BOLD);
		mvaddstr(row,(COLS-nw)/2-1,week);
		attron(COLOR_PAIR(3)|A_BOLD);
		mvaddnstr(row+1,(COLS-nt)/2-1,stime,5);
		attroff(COLOR_PAIR(3)|A_BOLD);
		refresh();
		sleep(1);
	}
	endwin();
}

