/*
 *写一个例程，来使信号量加1
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	int id=semget(0x8888,1,IPC_CREAT|0666);  //创建只有一个的信号量
	if(id<0){
		perror("semget");
		return -1;
	}
	if(semctl(id,0,SETVAL,0)<0){
		perror("semctl");
		return -1;
	}

	struct sembuf op;
	op.sem_num=0;
	op.sem_op=1;
	op.sem_flg=SEM_UNDO;

	char buf[1000];
	int fd=open("sem.txt",O_CREAT|O_WRONLY|O_APPEND,0644);
	if(fd<0){
		perror("open");
		return -1;
	}
	
	semop(id,&op,1);  //信号量加1
	while(1){
		scanf(" %[^\n]",buf);
		scanf("%*c");	
		write(fd,buf,strlen(buf)+1);
		if(strcmp(buf,"quit")==0)
			break;
	}
	close(fd);
	semctl(id,0,IPC_RMID);
	return 0;
}
