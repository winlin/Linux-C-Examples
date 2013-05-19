#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int* p;
int sid;
void func(int sig)
{
	shmdt(p);
	shmctl(sid, IPC_RMID, NULL);
	exit(0);
}
int main()
{
	signal(SIGINT, func);
	sid = shmget(0x1234, 16, IPC_CREAT|0666);
	if(sid<0){perror("shmget");return 1;}
	p = shmat(sid,NULL,0);
	if(p==NULL){perror("shmat");return 1;}
	int i=0;
	for(;;){
		p[0]=++i;
		p[1]=++i;
		p[2]=++i;
		p[3]=++i;
		sleep(1);
	}
	return 0;
}

