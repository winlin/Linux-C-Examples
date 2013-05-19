#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	//mkfifo("fifo",0666);
	int fd=open("fifo",O_RDONLY);
	if(fd<0){
		perror("open:");
		return -1;
	}
	printf("Open Succeed.\n");
	unsigned int n;
	while(1){
		if(read(fd,&n,sizeof(n))!=sizeof(n)){
			perror("read");
			return -1;
		}
		printf("%d\n",n);
	}
	close(fd);
	return 0;
}
