#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
int cnt=0;
int finished=0;
void statistics(int sig)
{
	if(sig==SIGUSR1){//做完了
	}
	else{//时间到了
	}
	printf("你的成绩%d\n", cnt*10);
	exit(0);
}
int main()
{
	signal(SIGALRM, statistics);
	signal(SIGUSR1, statistics);
	int i;
	srand(time(NULL));
	alarm(50);
	for(i=0; i<10; i++){
		int a=rand()%100;
		int b=rand()%100;
		int c;
		char op=rand()&1?(c=a+b,'+'):(c=a-b,'-');
		printf("%d%c%d=", a, op, b);
		int res;
		scanf("%d", &res);
		if(res==c) cnt++;
	}
	finished = 1;
	raise(SIGUSR1);
	//kill(getpid(),SIGUSR1);//printf("你的成绩%d\n", cnt*10);
	return 0;
}

