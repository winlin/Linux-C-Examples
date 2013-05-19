#ifndef LOGREADER_H
#define LOGREADER_H
#include "data.h"
class logreader
{
	private:
		char loginfile[30];
		char logfile[30];
	public:
		/*这个函数负责把文件变成要发送的数据集合*/
		void readlog(list<logmatchrec> *matches); 
	private:
		/*备份 把wtmpx按照日期备份 再把wtmpx清空 得到备份的文件名*/
		void backlogfile(char *backfilename);
		/*读取上次没有匹配的记录*/
		void readlogins(list<logrec> *logins);
		/*读取备份的日志文件,得到登录集合和登出集合*/
		void readbacklogfile(char* backfilename,list<logrec> *logins,list<logrec> *logouts);
		/*用登出集合去登录集合中匹配*/
		void matchlogs(list<logrec> *logins,list<logrec> *logouts,list<logmatchrec> *matchs);
		/*保存没有匹配成功的登录记录*/
		void savelogins(list<logrec> *logins);
		
};

#endif
