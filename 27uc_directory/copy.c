#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc,char* argv[])
{
	if(argc!=3){
		printf("Usage: %s file1 file2\n",argv[0]);
		return 0;
	}
	int fd1,fd2;
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1){
		printf("Open file %s failed\n",argv[1]);
		return -1;
	}
	fd2=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0664);
	if(fd2==-1){
		printf("Open file %s failed\n",argv[2]);
		close(fd1);
		return 0;
	}
	char cc[256];
	int num;
	while((num=read(fd1,cc,sizeof(cc)))>0){
		write(fd2,cc,num);
	}
	close(fd1);
	close(fd2);
        return 0;
}
