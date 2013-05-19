#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int i;
	for(i=0; i<5; i++){
		if(fork()==0){
			printf("process %d id %d\n", i, getpid());
			system("echo start;sleep 5;echo ok");
			return i+8;//break;
		}
		//....
	}
	int state;
	pid_t cid;
	while( (cid=wait(&state))>=0){
		printf("cid=%d, val=%d\n", cid, WEXITSTATUS(state));
	}
	sleep(10);
	return 0;
}

