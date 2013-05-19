#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>

int* p;
void endHandl(int sig)
{
	signal(sig,endHandl);
	shmdt(p);
}

int main(int argc,char* argv[])
{
	signal(SIGINT,endHandl);
	int sid=shmget(0x12345,0,0);
        //挂载一个共享内存，后面两个参数推荐为0
	p=shmat(sid,NULL,0);
	if(!p){
		perror("shmat");
		return -1;
	}
	
	int i=0;
	while(1){
		printf("%d\n",p[i]);
		sleep(1);
		i=(i+1)%4;
	}
	
	return 0;
}
