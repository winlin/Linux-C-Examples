#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{
	if(argc==1){
		printf("Usage: %s filenaem\n",argv[0]);
		return 0;
	}
	int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd<0){
		printf("Open file failed\n");
		return 0;
	}
	char c;
	while((c=getchar())!=EOF){
		write(fd,&c,1);
	}
	close(fd);
        return 0;
}
