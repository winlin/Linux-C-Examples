#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void func(int sig)
{
	//wait|waitpid
	printf("signal %d\n", sig);
}
int main()
{
	signal(SIGCHLD, func);
	signal(SIGINT, func);
	char* argv[]={"date","+%F %T",NULL};
	if(fork()==0){
		execvp("date", argv);
		printf("%m\n");
		exit(1);
	}
	if(fork()==0){
		execlp("date", "date", "+%F %T", NULL);
		printf("%m\n");
		exit(1);
	}
	printf("-----------\n");
	pause();
	printf("-----bye-----\n");
	return 0;
}

