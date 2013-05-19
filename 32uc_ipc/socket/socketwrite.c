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
	int fd=socket(AF_FILE,SOCK_DGRAM,0);
	if(fd<0){
		perror("socket");
		return -1;
	}
	
	struct sockaddr_un sau;
	memset(&sau,0,sizeof(sau));   /* clear */
	sau.sun_family=AF_FILE;
	strcpy(sau.sun_path,"sock");
	
	if(connect(fd,(struct sockaddr*)&sau,sizeof(sau))<0){
		perror("connect");
		return -1;
	}
	
	char buf[1024];
	int nums;
	while(1){
		printf("plese input: \n");
		//char *fgets(char *s, int size, FILE *stream);
		//最后一个参数不要为0，因为它需要的是一个FILE*
		fgets(buf,sizeof(buf),stdin);
		if(*buf=='\n')
			break;
		
		nums=write(fd,buf,strlen(buf));
		if(nums<1)
			break;
	}
	close(fd);
	return 0;
}
