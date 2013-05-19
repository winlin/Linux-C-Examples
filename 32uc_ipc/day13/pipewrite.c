#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	umask(0);
	mkfifo("./fifo", 0666);
	int fd = open("./fifo", O_WRONLY);
	if(fd<0){
		perror("open fifo");
		return 1;
	}
	printf("opened\n");
	unsigned int n=0;
	while(1){
		++n;
		if(write(fd, &n, sizeof(n))!=sizeof(n))
			break;
		sleep(1);
	}
	close(fd);
	unlink("./fifo");
}

