#ifndef CLIENTACCEPTER_H
#define CLIENTACCEPTER_H
#include <sys/socket.h>
#include <sys/types.h>
struct  threadp  //为给线程传递参数设计的结构体
{
	int  cfd;
    char cip[32];
};
class ClientAccepter
{
private:
	unsigned short port;//服务器端口  
	int fd;//服务器描述号
public:
	ClientAccepter();//构造器	
	int initSocket();//初始化服务器
	void setPort(unsigned short pt);//设置服务器端口
};
#endif
