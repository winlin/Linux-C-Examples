#include "logsender.h"
#include "dmsexception.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <strings.h>
#include  <netdb.h>

//构造器
LogNetSender::LogNetSender()
{
	bzero(serverip,sizeof(serverip));//string.h
	strcpy(serverip,"127.0.0.1");
	port=9999;
	bzero(filename,sizeof(filename));
	strcpy(filename,"fail.dat");
}
//发送主函数
void LogNetSender::sendLogs(list<matchedlogrec> *logs)
{
	try{
		//把上次发送失败的数据读取出来合并在一起		
		cout<<"读取上次发送失败记录......"<<endl;			
		readLogs(logs);
		cout<<"上次发送失败与本次发送记录总数:"<<logs->size()<<endl;			
		//初始化网络
		cout<<"连接服务器中......"<<endl;			
		initSocket();
		cout<<"开始发送数据......"<<endl;			
		//循环发送数据[可以封装成一个私有函数]
		
		while(logs->size()>0)
		{
			list<matchedlogrec>::iterator it=logs->begin();
			int re=send(fd,&(*it),sizeof(matchedlogrec),0);
			if(re==-1)
			{
				throw DMSException("发送数据失败!");
			}
			cout<<"发送 记录:"<<logs->size()<<":"<<it->logname<<";"<<it->logip<<endl;
			logs->erase(it);
		}
		cout<<"发送完毕!清检查日志，对发送失败的数据，要定点整合！"<<endl;
		
	}
	catch(DMSException e)
	{
		cout<<"发送异常!"<<endl;		
		//发生异常，就保存数据
		cout<<"保存发送失败数据中....!"<<endl;
		saveLogs(logs);
		cout<<"保存发送失败数据完毕!"<<endl;
		throw;
	}
}
void LogNetSender::setServerip(char *ip)
{
	bzero(serverip,sizeof(serverip));
	strcpy(serverip,ip);	
}
void LogNetSender::setPort(unsigned short pt)
{
	port=pt;
}
//初始化网络，连接服务器
void LogNetSender::initSocket()
{
	//采用数据报文的方式发送
	fd=socket(PF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		throw DMSException("建立socket错误！");
	}
	struct sockaddr_in  addr={};
	addr.sin_family=PF_INET;
	addr.sin_port=htons(port);
//	addr.sin_addr.s_addr=inet_addr(serverip);
	int re=connect(fd,(sockaddr*)&addr, sizeof(sockaddr_in));
	if(re==-1)
	{
		throw DMSException("连接服务器错误!");
	}	 
}
//读取上次发送失败的数据
void LogNetSender::readLogs(list<matchedlogrec> *logs)
{
	//打开剩余的登入记录文件。
	int fd=open(filename,O_RDONLY|O_EXCL);
	if(fd==-1)
	{
		//文件不存在等原因
		return;//不做任何处理
	}
	while(1)//循环读取记录
	{
		matchedlogrec log;
		int re=read(fd,&log,sizeof(log));
		if(re<=0)
		{
			//0 表示读取完毕 其他表示异常
			close(fd);
			return;//结束处理
		}
		logs->push_back(log);
	}
}
//保存本次发送失败的数据
void LogNetSender::saveLogs(list<matchedlogrec> *logs)
{
	//打开剩余的登入记录文件。
	int fd=open(filename,O_RDWR|O_CREAT|O_TRUNC);
	if(fd==-1)
	{
		//创建文件等异常
		return;//不做任何处理
	}
	while(logs->size()>0)
	{
		list<matchedlogrec>::iterator it=logs->begin();
		matchedlogrec log=*it;
		int re=write(fd,&log,sizeof(matchedlogrec));
		logs->erase(it);
		if(re==-1)
		{
			break;//错误发生，结束写数据
		}
	}
	close(fd);
}

