/*
 *使用select来实现server服务器
 *但是，由于select的延迟作用使得，多个客户端进行链接的时候，出现问题，
 *只能有一个用户链接上去，一个连上去会终止另一个链接
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>

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
	//定义文件描述符集
	fd_set  fdset;
	int fds[100];
	memset(fds,-1,sizeof(fds));
	
	int maxfd=-1;
	char ip[100]={0};
	char msg[1000]={0};
	int i;
	struct sockaddr_in cip;
	socklen_t len=sizeof(cip); //必须初始化
	while(1){
		FD_ZERO(&fdset);
		maxfd = fd;
		FD_SET(fd, &fdset);
		for(i=0; i<100; i++){
			if(fds[i]!=-1){
				FD_SET(fds[i], &fdset);
				if(fds[i]>maxfd) maxfd = fds[i];
			}
		}
		if(select(maxfd+1,&fdset,NULL,NULL,NULL)<0){
			continue;
		}
		//select检测到有链接到来
		if(FD_ISSET(fd,&fdset)){
			int s=accept(fd,(struct sockaddr*)&cip,&len);
			if(s>0){
				for(i=0;i<100;++i){
					if(fds[i]==-1)
						break;
				}
				fds[i]=s;
				inet_ntop(PF_INET,&cip.sin_addr,ip,sizeof(ip));
				printf("Welcome %s \n",ip);
				sprintf(msg,"your ip is %s\n",ip);
				write(s,msg,strlen(msg));
			}
		}
		
		for(i=0;i<100;++i){
			if((fds[i]!=-1)&&FD_ISSET(fds[i],&fdset)){
				int n;
				//while((n=read(fds[i],msg,sizeof(msg)))>0&&strncmp(msg,"\n",1))
				n=read(fds[i],msg,sizeof(msg));
				write(2,msg,n);
				if(strncmp(msg,"bye",3)==0){
					close(fds[i]);
					fds[i]=-1;
					continue;
				}
				write(fds[i],msg,n);
				//}	
			}
		}
	}
	close(fd);
	return 0;
}
