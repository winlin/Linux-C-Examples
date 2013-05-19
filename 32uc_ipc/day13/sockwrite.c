#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/un.h>

int main()
{
	int fd=socket(AF_FILE, SOCK_DGRAM, 0);
	if(fd<0){
		perror("socket");
		return 1;
	}

	struct sockaddr_un sau;
	memset(&sau, 0, sizeof(sau));
	sau.sun_family = AF_FILE;
	strcpy(sau.sun_path, "sock");
	if(connect(fd, (struct sockaddr*)&sau, sizeof(sau))<0){
		perror("bind");
		return 1;
	}
	
	char buf[1000];
	for(;;){
		printf("������:");
		fgets(buf,sizeof(buf),stdin);
		if(*buf=='\n') break;
		int len = write(fd, buf, strlen(buf));
		if(len<=0) break;
	}
	close(fd);
	//unlink("sock");
}

