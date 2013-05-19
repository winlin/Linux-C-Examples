#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int* p;
void func(int sig)
{
	shmdt(p);
	exit(0);
}
int main()
{
	signal(SIGINT, func);
	int sid = shmget(0x1234, 16, IPC_CREAT|0666);
	if(sid<0){perror("shmget");return 1;}
	p = shmat(sid,NULL,0);
	if(p==NULL){perror("shmat");return 1;}
	for(;;){
		printf("%d\n", *p);
		sleep(1);
	}
	return 0;
}

