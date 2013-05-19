#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc,char* argv[])
{
	key_t k;
	printf("unput key:");
	scanf("%x",&k);
	int mid=msgget(k,IPC_CREAT|0600);
	if(mid<0){
		perror("msgget");
		return -1;
	}
	printf("message queue id: %d\n",mid);
	
	
	return 0;
}
