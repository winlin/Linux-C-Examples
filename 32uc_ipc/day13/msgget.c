#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t k;
	printf("input key:");
	scanf("%x", &k);
	int mid = msgget(k, IPC_CREAT|0600);
	if(mid<0){
		perror("msgget");
		return 1;
	}
	printf("message queue id: %d\n", mid);
}

