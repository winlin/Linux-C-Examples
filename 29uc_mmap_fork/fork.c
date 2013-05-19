#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i;
	createchild(8);
	createchild(5);
	for(i=0; i<5; i++){
		printf("my pid=%d\n", getpid());
		sleep(1);
	}
	puts("parent process exited");
}
int createchild(int val)
{
	int i;
	if(fork()==0){
		for(i=0; i<10; i++){
			printf("cid=%d, parent=%d\n",getpid(),getppid());
			sleep(1);
		}
		printf("process %d exit\n", getpid());
		exit(val);//return val;
	}
		
}

