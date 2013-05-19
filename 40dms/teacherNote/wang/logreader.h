#ifndef LOGREADER_H
#define LOGREADER_H
#include<list>
#include "data.h"
#include<iostream>
using namespace std;
class logreader{
	char loginsfile[30];/*没有匹配的登录记录文件名*/
	char logfile[30];/*要备份的日志文件名*/
public:
	/*这个函数负责把文件变成要发送的数据*/
	void readlog(list<logmatchrec> *matches);
private:
	/*1.备份 把wtmpx按照日期备份
	 *  把wtmpx清空
	 *  得到备份的文件名
	 */
	void backlogfile(char *backfilename);
	/*2.读取上次没有匹配的记录*/
	void readlogins(list<logrec> *logins);
	/*3.读取备份的日志文件 得到登录集合和登出集合*/
	void readbacklogfile(char *backfilename,list<logrec> *logins,
			list<logrec> *logouts);
	/*4.用登出集和登录集合里匹配出最终的匹配集合*/
	void matchlogs(list<logrec> *logins,list<logrec> *logouts,
			list<logmatchrec> *matches);
	/*5.保存没有匹配成功的登录记录*/
	void savelogins(list<logrec> *logins);
};
#endif
