#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	//服务器指定一个端口号
	short port=5555;
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		perror("socket");
		return -1;
	}
	//绑定套接字信息AF,IP,port
	struct sockaddr_in sip;
	sip.sin_family=PF_INET;
	sip.sin_port=htons(port);  //端口号是按照网络序存储
	sip.sin_addr.s_addr=htonl(INADDR_ANY);  //INADDR_ANY 为0，一定是网络字节序
	
	if(bind(fd,(struct sockaddr*)&sip,sizeof(sip))<0){
		perror("bind");
		return -1;
	}
	
	listen(fd,10);
	
	struct sockaddr_in cip;
	socklen_t len=sizeof(cip); //必须初始化
	while(1){
		int s=accept(fd,(struct sockaddr*)&cip,&len);
		if(s<0){
			continue;
		}
		if(fork()!=0){
			close(s);
			continue;	
		}
		//子进程
		close(fd);
		char ip[100];
		inet_ntop(PF_INET,&cip.sin_addr,ip,sizeof(ip));
		printf("Welcome %s \n",ip);
		char msg[1000];
		sprintf(msg,"your ip is %s\n",ip);
		write(s,msg,strlen(msg));

		char rPrm='<';
		char lPrm='>';
		int rlen,wlen;
		while(1){
			write(s,&rPrm,1);
			rlen=read(s,msg,sizeof(msg));
			write(1,&lPrm,1);
			write(1,msg,rlen);
			if(strncmp(msg,"bye",3)==0)
				break;
		}	
		close(s);
		exit(-1);
	}
	
	return 0;
}
