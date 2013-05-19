/*
 *要注意处理多个子进程结束/终止时祖辈进程结束的顺序
 *同样也要注意祖辈进程结束时，子孙进程结束的情况
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

//处理子进程结束
void sigchild(int sig)
{
	signal(SIGCHLD,sigchild);
	while(waitpid(-1,NULL,WNOHANG)>0);
	//父进程不退出
}

//处理孙子进程结束
void siggrandson(int sig)
{
	signal(SIGCHLD,siggrandson);
	while(waitpid(-1,NULL,WNOHANG)>0);
	exit(0);   //子进程退出
}

int main()
{
	//对父进程进行子进程结束信号
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
	listen(fd,1);

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
		//对子进程注册孙子进程结束处理函数
		signal(SIGCHLD,siggrandson);
		close(fd);
		
		char ip[100]={0};
		inet_ntop(PF_INET,&cip.sin_addr,ip,sizeof(ip));
		printf("%s LOGIN\n",ip);

		int rlen;
		char msg[1000]={0};
		
		char name[22]={0};
		char myname[22]={"老男孩:"};
		//send myself name
		write(s,myname,strlen(myname));
		//recieve other name
		char pro[]={"输入你的名字(小于10个汉字):\n"};
		write(s,pro,sizeof(pro));
		rlen=read(s,name,sizeof(name));
		printf("His name is %s",name);
		name[strlen(name)-1]=':';
		
		//write to other
		int grandpid;
		if((grandpid=fork())==0){
			while((rlen=read(0,msg,sizeof(msg)))>0){
				write(s,msg,rlen);
				if(strncmp(msg,"bye",3)==0)
					exit(0);
				memset(msg,0,sizeof(msg));
			}
		}

                //read from other
		while((rlen=read(s,msg,sizeof(msg)))>0){
			write(1,name,strlen(name));
			write(1,msg,rlen);
			if(strncmp(msg,"bye",3)==0){
				break;
			}
			memset(msg,0,sizeof(msg));
		}
		kill(grandpid); //当子进程(读取功能)意外结束时，也结束孙子进程(输入功能)
		close(s);
		exit(0);
	}
	close(fd);
	return 0;	
}
