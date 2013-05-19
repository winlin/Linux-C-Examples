#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigchild(int sig)
{
	signal(SIGCHLD,sigchild);
	while(waitpid(-1,NULL,WNOHANG)>0);
	exit(0);
}

int main(int argc,char* argv[])
{
	signal(SIGCHLD,sigchild);
	if(argc!=2)
		exit(0);
	
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in sip;
	sip.sin_family=AF_INET;
	sip.sin_port=htons(5555);
	inet_pton(AF_INET,argv[1],&(sip.sin_addr));
	socklen_t len=sizeof(sip);
	if(connect(fd,(struct sockaddr*)&sip,len)){
		perror("connect");
		exit(-1);
	}
	printf("Link successfully.\n");
	int rlen;
	char msg[1000]={0};
	char name[22]={0};
	//recieve other's name
	rlen=read(fd,name,sizeof(name));
	
	//write to other
	if(fork()==0){
		while((rlen=read(0,msg,sizeof(msg)))>0){
			write(fd,msg,strlen(msg));
			if(strncmp(msg,"bye",3)==0)
				exit(0);
			memset(msg,0,sizeof(msg));
		}
	}
	//read to other
	while((rlen=read(fd,msg,sizeof(msg)))>0){
		write(1,name,strlen(name));
		write(1,msg,rlen);
		if(strncmp(msg,"bye",3)==0)
			exit(0);
		memset(msg,0,sizeof(msg));
	}
	return 0;
}
