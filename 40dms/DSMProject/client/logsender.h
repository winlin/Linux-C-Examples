#ifndef LOGSENDER_H
#define LOGSENDER_H
#include <list>
#include "logreader.h"
//发送接口
class ILogSend
{
public:
	virtual void sendLogs(list<matchedlogrec> *logs)=0;
};
//发送的网络实现类[可以是文件实现，控制台实现等
class LogNetSender:public ILogSend
{
private:
	char filename[52];//保存发送失败数据的文件名
	char serverip[32];//服务器IP地址
	unsigned short  port;//服务器端口
	int fd;//网络描述符号
public:
	LogNetSender();
	virtual void sendLogs(list<matchedlogrec> *logs);//发送主函数

	void setServerip(char *ip);
	void setPort(unsigned short pt);
private:
	void initSocket();//初始化网络，连接服务器
	void readLogs(list<matchedlogrec> *logs); //读取上次发送失败的数据
	void saveLogs(list<matchedlogrec> *logs); //把存本次发送失败的数据
};
#endif
