#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void func(int sig)
{
	signal(sig, func);
	int stat;
	pid_t cid;
	while( (cid=waitpid(-1,&stat,WNOHANG))>0 )
		printf("cid %d, ret %d\n",cid,WEXITSTATUS(stat));
}
int main()
{
	signal(SIGCHLD, func);
	int i;
	for(i=0; i<5; i++){
		if(fork()==0){
			printf("cid=%d, parent=%d\n", getpid(),getppid());
			sleep(5+0*i);
			printf("%d exited\n", getpid());
			exit(i*10);
		}
	}
	int n=0;
	for(i=0;i<2;i++){
		n += 10;
		printf("n=%d\n", n);
		sleep(100);
	}
}

