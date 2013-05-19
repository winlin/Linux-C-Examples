#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>

int id;

int main(int argc,char* argv[])
{
        //获得一个有8个信号的信号量数组
	id=semget(0x13800,8,0);
	if(id<0){
		perror("semget");
		return -1;
	}
	//设置第6个信号量的值为2
	semctl(id,5,SETVAL,2);
	
	struct sembuf sem[8];
	
	while(1){
		sem[0].sem_num=5;
		sem[0].sem_op=-1;    //第6个信号量值加1
		sem[0].sem_flg=SEM_UNDO;

		sem[1].sem_num=1;
		sem[1].sem_op=-1;
		sem[1].sem_flg=SEM_UNDO;

		/*
		  printf("申请第2，5信号量的信号灯....\n");
		使用sem数组的前2个信号量操作，即sem[0],sem[1]
		if(semop(id,sem,2)<0){
			perror("semop");
			return -1;
		}
		*/
		printf("申请第2个信号量的一个信号灯....\n");
		if(semop(id,&sem[1],1)<0){
			perror("semop");
		}
		printf("申请第2个信号量成功\n");
		
		printf("申请第5个信号量的一个信号灯....\n");
		if(semop(id,&sem[0],1)<0){
			perror("semop");
		}
		printf("申请第5个信号量成功\n");
			
	}
	return 0;
}
