#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>
#include <stdlib.h>
int id;

void sigint(int sig)
{
	signal(sig,sigint);
	semctl(id,0,IPC_RMID);  //删除操作
	exit(-1);
}

int main(int argc,char* argv[])
{
	signal(SIGINT,sigint);
	//创建一个有8个信号的信号量数组
	int id=semget(0x13800,8,IPC_CREAT|0666);
	if(id<0){
		perror("semget");
		return -1;
	}
	//设置第6个信号量的值为2
	semctl(id,5,SETVAL,2);
	semctl(id,1,SETVAL,2);
	char ch;
	struct sembuf sem[8];
	while(1){
		printf("是否增加一个信号量(y/n)?\n");
		scanf(" %c",&ch);
		if(ch=='n')
			continue;
		else if(ch=='y'){
			sem[0].sem_num=5;
			sem[0].sem_op=1;    //第6个信号量值加1
			sem[0].sem_flg=SEM_UNDO;

			sem[1].sem_num=1;
			sem[1].sem_op=1;
			sem[1].sem_flg=SEM_UNDO;
			
			//使用sem数组的前2个信号量操作，即sem[0],sem[1]
			if(semop(id,sem,2)<0){
				perror("semop");
				return -1;
			}
		}
	}
	return 0;
}
