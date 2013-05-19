#include <ncurses.h>

int main()
{
	initscr();
	for(;;){
		int ch = mvgetch(8,0);
		if(ch=='q'||ch=='Q') break;
		mvwaddch(stdscr,0,0,ch);
		mvaddch(0,COLS-1,ch);
		refresh();
	}
	endwin();
}

