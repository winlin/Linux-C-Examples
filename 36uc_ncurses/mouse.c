/*
 *鼠标操作
 */
#include <curses.h>

int main()
{   
	initscr();
	char* menu[]={
		"HONG SHAO YU",
		"HU PI JIAN JIAO",
		"XI HONG SI",
		"QUIT",
		NULL
	};
	noecho();
	WINDOW* w=newwin(7,14,(LINES-7)/2-1,(COLS-7)/2-1);
	showmenu(w,menu,-1);
	keypad(w,TRUE);
	mousemask(ALL_MOUSE_EVENTS,NULL);
	curs_set(0);
	while(1){
		int ch=wgetch(w);
		if(ch!=KEY_MOUSE)
			continue;
		MEVENT e;
		getmouse(&e);
		if(e.bstate&BUTTON1_PRESSED){
			mvprintw(0,0,"%02d %02d",e.y,e.x);
			
		}
	}
	endwin();
	
	return 0;
}
