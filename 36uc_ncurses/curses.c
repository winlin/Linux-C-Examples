/*
 *curses全屏幕编程
 *所有curses的输出都是在虚拟屏幕上输出，除非调用refresh()
 *编译的时候添加: -lncurses
 */
#include <stdio.h>
#include <curses.h>
#include <string.h>

int main()
{   
	initscr();   //初始化全屏幕，全局的WINDOW* stdscr代表整个屏幕
	printw("hello world.");
	mvprintw(5,6,"hello world.");
	//画出一行的一部分
	mvhline(LINES/2,5,'=',COLS-10);
	//画出一列的一部分
	mvvline(2,4,'|',LINES-4);
	
	//LINES,COLS系统初始化的代表屏幕的行和列,编号从零开始
	mvprintw(LINES/2-1,(COLS-strlen("hello world."))/2-1,"hello world");

        //画出一个框
	box(stdscr,0,0);
	//隐藏光标
	curs_set(0);
	
	refresh();
	//scanw()
	getch();
	endwin();
	
	return 0;
}
