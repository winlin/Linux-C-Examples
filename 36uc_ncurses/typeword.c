/*
 *利用curses库编写打字游戏
 */
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct Word{
	char c;
	short int x;
	short int y;
	short int step;  //一个单词的速度
	
}Word;

int nums;
int step;
Word* ary;

pthread_cond_t mycond=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mymutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mymutex2=PTHREAD_MUTEX_INITIALIZER;

//获得字符数组
void getChars(int width,Word* ary,int nums)
{
	int i;
	char cc;
	for(i=0;i<nums;++i){
		cc='!';
		cc=cc+rand()%96;
		ary[i].c=cc;
		ary[i].y=0;
		ary[i].x=1+width*(i+1);
	}	
}

//改变一个字符的坐标
void* changXY(void* arg)
{
	Word* pary=(Word*)arg;
	int mm=0;
	while(mm<LINES){
		pthread_mutex_lock(&mymutex1);
		(*pary).y+=step;
		mm+=step;
		pthread_cond_signal(&mycond);
		pthread_mutex_unlock(&mymutex1);
	}
	return NULL;	
}

int main()
{
	initscr();
	int i;
	
	printw("Please input the number of words you want:");
	scanw("%d",&nums);
	printw("Plses input your speed (1-5):");
	scanw("%d",&step);
	
	int width=COLS/(nums+1);
	ary=(Word*)calloc(nums,sizeof(Word));
		
	srand(time(NULL));
	getChars(width,ary,nums);

	pthread_mutex_lock(&mymutex1);
	pthread_t pid[nums];
	for(i=0;i<nums;++i){
		Word* pary=(ary+i);
		pthread_create(&pid[i],NULL,changXY,(void*)pary);
	}
	
	pthread_mutex_lock(&mymutex2);
	while(1){
		pthread_cond_wait(&mycond,&mymutex1);
		for(i=0;i<nums;++i){
			mvprintw(ary[i].y,ary[i].x,"%c",ary[i].c);
			refresh();
		}
	}
	pthread_mutex_unlock(&mymutex2);


	pthread_mutex_unlock(&mymutex1);
	pthread_mutex_destroy(&mymutex1);
	pthread_mutex_destroy(&mymutex2);
	pthread_cond_destroy(&mycond);
	
	endwin();

	return 0;
}
