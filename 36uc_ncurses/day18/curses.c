#include <ncurses.h>
#include <string.h>

int main()
{
	initscr();//全局的WINDOW* stdscr代表整个终端窗口
	//LINES,COLS
	const char* str = "hello, %s!";
	mvhline(LINES/2,5,'-',COLS-10);
	mvvline(2,4,'|',LINES-4);
	mvprintw(LINES/2-1, (COLS-strlen(str))/2-1, str, "芙蓉");
	box(stdscr,0,0);
	curs_set(0);
	refresh();
	getch();
	endwin();
}

