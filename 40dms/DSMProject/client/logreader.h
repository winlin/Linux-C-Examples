#ifndef LOGREADER_H
#define LOGREADER_H
#include <list>
#include "data.h" 
using  namespace std;
class ILogRead
{
public:
	virtual void readLogs(list<matchedlogrec> *logs)=0;
};
//这个设计？？？？？
class  LogReader:public ILogRead
{
private:
	char  logfile[255];
	char  loginsfile[255];
public:
	LogReader();	
	virtual void readLogs(list<matchedlogrec> *logs);
	void setLogfile(char *file);
	void setLoginsfile(char *file);
	
public:
	void backup(char*backfile);
	void readLogins(list<logrec> *logins);
	void readLogFile(char*backfile,list<logrec>*logins,list<logrec>*logouts);
	void match(list<logrec>*logins,list<logrec>*logouts,list<matchedlogrec> *logs);
	void saveLogins(list<logrec> *logins);
};
#endif
