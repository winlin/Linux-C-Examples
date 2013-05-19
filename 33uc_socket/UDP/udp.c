/*
 *TCP/UDP不同的协议可以共用一个端口
 *最好不要在case语句里面定义变量，以防止出现以外结果
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char* argv[])
{
	puts("请输入自己使用的端口号:");
	short port;
	scanf("%hd",&port);
	//创建套接字
	int s=socket(AF_INET,SOCK_DGRAM,0);
	if(s<0){
		perror("socket");
		return -1;
	}
	//绑定套接字
	struct sockaddr_in si;
	si.sin_family=AF_INET;
	si.sin_addr.s_addr=htonl(INADDR_ANY);
	si.sin_port=htons(port);
	
	if(bind(s,(struct sockaddr*)&si,sizeof(si))<0){
		perror("bind");
		return -1;
	}
	//收发数据
	/*
	  s:  sned ip port message
	  g:  get
	  r:  reply message
	  q:  qiut
    	 */
	printf("s ip port message|g|r message|q\n");
	char cmd;
	char ip[20]={0};
	char cport[10]={0};
	char msg[1000]={0};
	socklen_t len;
	while(1){
		scanf(" %c",&cmd);
		if(cmd=='q')
			break;
		switch(cmd){
		case 's':
			scanf("%s%hd",ip,&port);
			inet_pton(AF_INET,ip,&(si.sin_addr.s_addr));
			si.sin_port=htons(port);
		case 'r':
			fgets(msg,sizeof(msg),stdin);
			sendto(s,msg,strlen(msg),0,(struct sockaddr*)&si,sizeof(si));
			memset(msg,0,sizeof(msg));
			break;
		case 'g':
			len=sizeof(si);
			//case里面定义的变量有危险性
			int n=recvfrom(s,msg,sizeof(msg),MSG_DONTWAIT,(struct sockaddr*)&si,&len);
			if(n<=0){
				printf("no message.\n");
				break;
			}
			inet_ntop(si.sin_family,&si.sin_addr,ip,sizeof(ip));
			write(2,ip,strlen(ip)); //2不带缓冲
			sprintf(cport,"@%hd",ntohs(si.sin_port));
			write(2,cport,strlen(cport));
			write(2,":",1);
			write(2,msg,n);
			memset(msg,0,sizeof(msg));
			break;
		default:
			break;
			
		}
	}
		
	return 0;
}
