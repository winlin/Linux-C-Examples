#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigchild(int sig)
{
	signal(SIGCHLD,sigchild);
	while(waitpid(-1,NULL,WNOHANG)>0);
}

int main()
{
	signal(SIGCHLD,sigchild);
	//服务器指定一个端口号
	short port=5555;
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		perror("socket");
		exit(-1);
	}
	//绑定套接字
	struct sockaddr_in sip;
	sip.sin_family=PF_INET;
	sip.sin_port=htons(port);
	sip.sin_addr.s_addr=htonl(INADDR_ANY);

	if(bind(fd,(struct sockaddr*)&sip,sizeof(sip))<0){
		perror("bind");
		exit(-1);
	}
	listen(fd,50);

	struct sockaddr_in cip;
	socklen_t len=sizeof(cip);
	while(1){
		int s=accept(fd,(struct sockaddr*)&cip,&len);
		if(s<0)
			continue;
		if(fork()!=0){
			close(s);
			continue;
		}
		//child process
		close(fd);
		char ip[100]={0};
		inet_ntop(PF_INET,&cip.sin_addr,ip,sizeof(ip));
		printf("%s LOGIN\n",ip);

		int rlen;
		char msg[1000]={0};
		
		char name[22]={0};
		//char myname[22]={"老男孩:"};
		//send myself name
		//write(s,myname,sizeof(myname));
		
		//recieve client's name
		char pro[]={"输入你的名字(小于10个汉字):\n"};
		write(s,pro,sizeof(pro));
		rlen=read(s,name,sizeof(name));
		name[strlen(name)-1]=':';
		
		//write to other
		if(fork()==0){
			while((rlen=read(0,msg,sizeof(msg)))>0){
				write(s,msg,rlen);
				if(strncmp(msg,"bye",3)==0)
					exit(0);
				memset(msg,0,sizeof(msg));
			}
		}

                //read from other
		while((rlen=read(s,msg,sizeof(msg)))>0){
			write(1,name,sizeof(name));
			write(1,msg,rlen);
			if(strncmp(msg,"bye",3)==0)
				break;
			memset(msg,0,sizeof(msg));
		}
		
		close(s);
		exit(0);
	}
	close(fd);
	return 0;	
}
