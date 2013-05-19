#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t k;
	printf("input key:");
	scanf("%x", &k);
	int mid = msgget(k, 0);
	if(mid<0){
		perror("msgget");
		return 1;
	}
	printf("found, mid=%d\n", mid);
	if(msgctl(mid, IPC_RMID, NULL)<0)
		perror("msgctl");
	return 0;
}

