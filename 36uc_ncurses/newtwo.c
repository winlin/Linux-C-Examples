/*
 *使用curses库设计一个打字程序
 */
#include <curses.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct Word{
	char ch;
	int x,y;
	int step;
}Word;
typedef struct inputChar{
	char ch;
	short int flag;   //把存放输入字符的数组循环利用
}inputChar;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

Word *arry;
inputChar*  inputarry;
int score=0;
int lose=0;

void initArry(int len,int cols,int step)
{
	int i;
	for(i=0;i<len;++i){
	arry[i].ch=rand()%26+'a';
	arry[i].x=(i+1)*cols-1;
	arry[i].y=0;
	arry[i].step=step;
	}
}

void* showChars(void* arg)
{
	int nums = *((int*)arg);
	while(arry){
		int i;
		pthread_mutex_lock(&m);
		for(i=0;i<nums;++i){
			int j;
			for(j=0;j<arry[i].y;++j)
				mvaddch(j,arry[i].x,' ');
			mvaddch(arry[i].y,arry[i].x,arry[i].ch);
			arry[i].y += arry[i].step;
		}
		pthread_mutex_unlock(&m);	
		refresh();
		//已经无效的重置
		pthread_mutex_lock(&m);
		for(i=0;i<nums;++i){
			if(arry[i].y>=LINES-1 && arry[i].ch!=' '){
				arry[i].ch=rand()%26+'a';
				arry[i].y=0;
				++lose;
			}
		}
		pthread_mutex_unlock(&m);
		sleep(1);
	}
	return NULL;
}

void* inputChars(void* arg)
{
	int nums =*((int*)arg);
	while(1){
		noecho();
		int ch=getch();
		//被击中，设置为空格
		int n;
		pthread_mutex_lock(&m);
		for(n=0;n<nums;++n){
			if(ch==arry[n].ch){
				++score;
				arry[n].ch=' ';
			}
		}
		pthread_mutex_unlock(&m);
	}
}

int main()
{   
	initscr();
	srand(time(NULL));
	
	int selfStep=1;
	int selfNums=8;
	arry = (Word*)calloc(0,selfNums*sizeof(Word));
	
	initArry(selfNums,COLS/(selfNums+1),selfStep);
	
	pthread_t pid[2];
	pthread_create(&pid[0],NULL,showChars,(void*)&selfNums);
	pthread_create(&pid[1],NULL,inputChars,(void*)&selfNums);
	
	pthread_join(pid[0],NULL);
	pthread_join(pid[1],NULL);

	free(inputarry);
	free(arry);
	pthread_mutex_destroy(&m);
	
	endwin();
	return 0;
}
