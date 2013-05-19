#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	if(fork()==0){//第一个孩子
		printf("1st child: %d\n", getpid());
		for(;;){
			putchar('.');
			fflush(stdout);
			sleep(1);
		}
	}
	else if(fork()==0){//第二个孩子
		printf("2nd child: %d\n", getpid());
		int i;
		for(i=0; i<5; i++){
			putchar('*');
			fflush(stdout);
			sleep(1);
		}
		return 5;//exit(0);
	}
	else{//父进程
		pid_t cid;
		int state;
		while( (cid=wait(&state))>0 ){
			if(WIFEXITED(state)){
				printf("%d正常%d\n",cid,WEXITSTATUS(state));
			}
			else{//if(WIFSIGNALED(state))
				printf("%d异常%d\n",cid,WTERMSIG(state));
			}
		}
	}
}

