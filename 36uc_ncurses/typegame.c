/*Wolf 做的*/
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

typedef struct Char{
	char ch;
	int y;
	int x;
}Char;

Char chars[20];
int end=0;
int good=0;
int loss=0;
pthread_mutex_t m;

void clrscr(){
	int i,j;
	for(i=0;i<LINES;i++){
		for(j=0;j<COLS;j++){
			if(!end) mvaddch(i,j,' ');
			else return;
		}
	}
	refresh();
}
void * thdShow(void *p){
	int i;
	for(;;){
		if(end) return NULL;
		clrscr();
		for(i=0;i<sizeof(chars)/sizeof(chars[0]);i++){
			if(chars[i].y>=LINES) {
				pthread_mutex_lock(&m);
				chars[i].ch='A'+rand()%26;
				chars[i].y=0;
				loss++;
				pthread_mutex_unlock(&m);
			}
			if(isupper(chars[i].ch)){
				attron(COLOR_PAIR(2));
				mvaddch(chars[i].y,chars[i].x-1,' ');
				mvaddch(chars[i].y,chars[i].x,chars[i].ch);
				mvaddch(chars[i].y,chars[i].x+1,' ');
				attroff(COLOR_PAIR(2));
				pthread_mutex_lock(&m);
				chars[i].y++;
				pthread_mutex_unlock(&m);
			}else if(chars[i].ch=='*'){
				attron(COLOR_PAIR(3));
				mvaddch(chars[i].y,chars[i].x-1,'*');
				mvaddch(chars[i].y,chars[i].x,chars[i].ch);
				mvaddch(chars[i].y,chars[i].x+1,'*');
				attroff(COLOR_PAIR(3));
				pthread_mutex_lock(&m);
				chars[i].ch='A'+rand()%26;
				chars[i].y=0;
				good++;
				pthread_mutex_unlock(&m);
			}
		}
		mvaddch(LINES-1,COLS/2,' ');
		refresh();
		sleep(1);
	}
}

void * thdGet(void *p){
	char ch;
	for(;;){
		if(end) return NULL;
		ch=getch();
		int i;
		for(i=0;i<sizeof(chars)/sizeof(chars[0]);i++){
			if(toupper(ch)==chars[i].ch){
				pthread_mutex_lock(&m);
				chars[i].ch='*';
				pthread_mutex_unlock(&m);
				break;
			}
		}
	}
}

void func(int sig){
	char buf[20];
	mvhline(LINES/2-3,20,'=',COLS-40);
	sprintf(buf,"Get: %d",good);
	mvaddstr(LINES/2-1,(COLS-strlen(buf))/2-1,buf);
	sprintf(buf,"Loss: %d",loss);
	mvaddstr(LINES/2+1,(COLS-strlen(buf))/2-1,buf);
	mvhline(LINES/2+3,20,'=',COLS-40);
	refresh();
	end=1;
	sleep(2);
	pthread_mutex_destroy(&m);
	endwin();
	exit(0);
}

int main(){
	initscr();
	signal(SIGINT,func);
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_YELLOW,COLOR_RED);
	init_pair(2,COLOR_RED,COLOR_YELLOW);
	int i;
	pthread_mutex_init(&m,NULL);
	srand(time(NULL));
	for(i=0;i<sizeof(chars)/sizeof(chars[0]);i++){
		chars[i].ch='A'+rand()%26;
		chars[i].y=0;
		chars[i].x=3*i+15;
	}
	pthread_t thd_show,thd_get;
	pthread_create(&thd_show,NULL,thdShow,NULL);
	pthread_create(&thd_get,NULL,thdGet,NULL);
	pthread_join(thd_show,NULL);
	pthread_join(thd_get,NULL);
	return 0;
}

