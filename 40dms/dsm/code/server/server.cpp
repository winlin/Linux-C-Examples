#include "server.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

using std::cout;
using std::cerr;
using std::endl;

void printerr(const char* strerr)
{
	perror(strerr);
	exit(-1);
}

void* pFun(void* arg)
{
	int csockid=*(int*)arg;
	log_match_rec logrec;
	int len=sizeof(logrec);

	int rc;
	int byte;
	while(1){
		for(byte=0;byte<len;byte+=rc){
			rc=recv(csockid,(char*)&logrec+byte,len-byte,MSG_NOSIGNAL);
			if(rc==0)
				break;
			if(rc<0&&errno!=EINTER){
				printerr("recv() failed");
			}
		}
		
		cachePool->push_data(logrec);
	}
}

void inputDB()
{
	/*从缓冲池中取出指令，然后执行Proc命令把数据添加到数据库*/
}

void Server::acceptRec()
{
	int sockfid=socket(AF_INET,SOCK_STREAM,0);
	if(sockfid==-1)
		printerr("socket()");
	
	sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9999);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	socklen_t addrlen=sizeof(addr);
	
	if(bind(sockfid,(sockaddr*)&addr,sizeof(addr))<0)
		printerr("bind");
	listen(sockfid,20);

	sockaddr_in cip;
	socklen_t len=sizeof(cip);
	while(1){
		int cid=accept(sockfid,(struct sockaddr*)&cip,&len);
		if(s<0)
			continue;
		pthread_t pid;
		pthread_create(&pid,NULL,pFun,(void*)&cid);
	}	
}
