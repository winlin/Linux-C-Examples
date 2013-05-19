#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc,char* argv[])
{
	key_t k;
	printf("input key ");
	scanf("%x",&k);
	int mid=msgget(k,0);
	if(mid==-1){
		perror("msgget");
		return -1;
	}
	if(msgctl(mid,IPC_RMID,NULL)<0){
		perror("msgctl");
		return -1;
	}
	puts("delete succeed.\n");
	return 0;
}
