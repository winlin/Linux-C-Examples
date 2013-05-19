/*
 *本地套接字
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <linux/un.h>

int main(int argc,char* argv[])
{
	//AF_LOCAL相当于AF_FILE
	int fd=socket(AF_LOCAL,SOCK_DGRAM,0);
	if(fd<0){
		perror("socket");
		return -1;
	}
	
	struct sockaddr_un sau;
	memset(&sau,0,sizeof(sau));   /* clear */
	sau.sun_family=AF_FILE;
	strcpy(sau.sun_path,"sock");
	
	if(bind(fd,(struct sockaddr*)&sau,sizeof(sau))<0){
		perror("bind");
		return -1;
	}
	
	char buf[1024];
	int nums;
	while(1){
		nums=read(fd,buf,sizeof(buf));
		if(nums<1)
			break;
		write(1,buf,nums);
	}
	close(fd);
	return 0;
}
