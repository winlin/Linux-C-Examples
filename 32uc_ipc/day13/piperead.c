#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	umask(0);
	mkfifo("./fifo", 0666);
	int fd = open("./fifo", O_RDONLY);
	if(fd<0){
		perror("open fifo");
		return 1;
	}
	printf("opened\n");
	unsigned int n;
	while(1){
		if(read(fd, &n, sizeof(n))!=sizeof(n))
			break;
		printf("%d\n", n);
	}
	close(fd);
	unlink("./fifo");
}

