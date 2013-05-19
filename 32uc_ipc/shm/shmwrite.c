#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int* p;
int sid;

void endHandl(int sig)
{
	signal(sig,endHandl);
	//分离一个共享内存
	shmdt(p);
	//删除一个共享内存
	shmctl(sid,IPC_RMID,NULL);
}

void atEnd(void)
{
	//分离一个共享内存
	shmdt(p);
	//删除一个共享内存
	shmctl(sid,IPC_RMID,NULL);
}

int main(int argc,char* argv[])
{
	signal(SIGINT,endHandl);
	atexit(atEnd);
	//创建一个共享内存
	sid=shmget(0x12345,16,IPC_CREAT|0666);
	if(sid<0){
		perror("shmget");
		return -1;
	}
	//挂载一个共享内存
	p=shmat(sid,NULL,0);
	if(!p){
		perror("shmat");
		return -1;
	}
	int i,j=0;
	while(1){
		for(i=0;i<4;++i){
			p[i]=++j;
			sleep(1);
		}
	}
	
	return 0;
}
