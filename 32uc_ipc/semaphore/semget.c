/*
 *写一个例程，来获得信号量，信号量会减1
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int id=semget(0x8888,1,0);  //获得一个信号量
	if(id<0){
		perror("semget");
		return -1;
	}
	struct sembuf op;
	op.sem_num=0;
	op.sem_op=-1;
	op.sem_flg=SEM_UNDO;

	int fd=open("sem.txt",O_RDONLY);

	char buf[1000];
	int len;

	puts("waiting...");

	while(semop(id,&op,1)<0); //获得信号量
	
	while(1){
		if((len=read(fd,buf,sizeof(buf)))>0){
			if(strcmp(buf,"quit")==0)
				break;
			write(1,buf,len);
		}
	}
	close(fd);
	unlink("sem.txt");
	return 0;
}
