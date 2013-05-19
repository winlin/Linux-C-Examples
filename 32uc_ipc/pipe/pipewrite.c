#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	mkfifo("fifo",0666);
	int fd=open("fifo",O_WRONLY);
	if(fd<0){
		perror("open:");
		return -1;
	}
	printf("Open Succeed.\n");
	unsigned int n=0;
	while(1){
		if(write(fd,&(n),sizeof(n))!=sizeof(n)){
			perror("read");
			return -1;
		}
		sleep(1);
		++n;
	}
	close(fd);
	return 0;
}
