#include "logreader.h"
#include "dmsexception.h"
#include <string.h>
#include <cstdlib>
#include <string>
#include <strings.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>

//构造函数
LogReader::LogReader()
{
	char file[]="logins.dat";	
	bzero(loginsfile,255);
	memcpy(loginsfile,file,strlen(file));
}
//日志读取的主函数
void LogReader::readLogs(list<matchedlogrec> *logs)
{
	
	char backfile[255];
	bzero(backfile,255);
	try{
		backup(backfile);
		list<logrec> logins;
		cout<<"读取上次剩余登入记录......"<<endl;
		readLogins(&logins);
		cout<<"上次剩余数:"<<logins.size()<<endl;
		list<logrec> logouts;
		cout<<"读取系统日志......"<<endl;
		readLogFile(backfile,&logins,&logouts);
		cout<<"登入记录数:"<<logins.size()<<";登出记录数:"<<logouts.size()<<endl;
		cout<<"匹配登入／登出数据中......"<<endl;
		match(&logins,&logouts,logs);
		cout<<"匹配剩余登入记录数:"<<logins.size()<<";匹配成功数:"<<logs->size()<<endl;
		cout<<"保存剩余登入数据......"<<endl;
		saveLogins(&logins);
	}
	catch(DMSException e)
	{
		throw;
	}
}
//设置采集的日志文件
void LogReader::setLogfile(char *file)
{
	memcpy(logfile,file,strlen(file));	
}
//剩余登入记录的保存文件名
void LogReader::setLoginsfile(char *file)
{
	memcpy(loginsfile,file,strlen(file));	
}
//备份日志文件
void LogReader::backup(char*backfile)
{
		//备份文件名 dmsyyyymmdd		
		//得到系统时间
		time_t t=time(NULL); 
		struct tm* st=localtime(&t);
		sprintf(backfile,"dms%04d%02d%02d%02d%02d",st->tm_year+1900,st->tm_mon+1,st->tm_mday,st->tm_hour,st->tm_min);
		string backcmd("./backup.sh ");
		backcmd+=" wtmpx ";
		backcmd+=backfile;
		backcmd+="  2>/dev/null ";
		int re=system(backcmd.data());
                cout<<re<<endl; 
		if(re!=0)		
		{
			throw  DMSException("备份指令错误!"); 
		}
}
//读取上次匹配剩余的登入记录
void LogReader::readLogins(list<logrec> *logins)
{
	//打开剩余的登入记录文件。
	int fd=open(loginsfile,O_RDONLY|O_EXCL);
	if(fd==-1)
	{
		//文件不存在等原因
		return;//不做任何处理
	}
	while(1)//循环读取记录
	{
		logrec log;
		int re=read(fd,&log,sizeof(log));
		if(re<=0)
		{
			//0 表示读取完毕 其他表示异常
			close(fd);
			return;//结束处理
		}
		logins->push_back(log);
	}
}
//读取日志文件
void LogReader::readLogFile(char*backfile,list<logrec>*logins,list<logrec>*logouts)
{
	int fd=open(backfile,O_RDONLY|O_EXCL);
	if(fd==-1)
	{
		throw  DMSException("打开文件错误!"); 
	}
	while(1)
	{
		logrec logs={};
		short type;
		bzero(logs.logname,32);
		int re=read(fd,logs.logname,32);
		if(re<=0)
		{
			break;
		}		
		
		lseek(fd,36,SEEK_CUR);	
		re=read(fd,&logs.pid,sizeof(pid_t));
		logs.pid=ntohl(logs.pid);
				
		re=read(fd,&type,2);
		
		//处理字节序
		/*由于我们实验下的系统是Linux，
		实际的日志文件是Unix，采用不同的字节序,所以作一个转换*/
		type=ntohs(type);		
		
		lseek(fd,6,SEEK_CUR);	
		re=read(fd,&logs.logtime,4);	
		logs.logtime=ntohl(logs.logtime);		
		
		lseek(fd,28,SEEK_CUR);	
		short size;
		re=read(fd,&size,2);
		size=ntohs(size);
		bzero(logs.logip,257);
		re=read(fd,logs.logip,257);
		logs.logip[size]=0;
		if(logs.logname[0]!='.')
		{	

			if(type==7)
			{
				/*
				cout<<logs.logname<<";";
				cout<<logs.pid<<";";
				cout<<logs.logtime<<";";
				cout<<logs.logip<<";"<<endl;*/
				logins->push_back(logs);
			}
			else if(type==8)
			{
				logouts->push_back(logs);
			}
		}
		lseek(fd,1,SEEK_CUR);
	}
	close(fd);
}
//匹配日志文件
void LogReader::match(list<logrec>*logins,list<logrec>*logouts,list<matchedlogrec> *logs)
{
	list<logrec>::iterator i=logouts->begin();
	bool b=0;
	while(i!=logouts->end())
	{	
		b=0;
		list<logrec>::iterator j=logins->begin();
		while(j!=logins->end())
		{
			if(i->pid==j->pid &&
				!strncmp(i->logname,j->logname,strlen(i->logname))&&
				!strncmp(i->logip,j->logip,strlen(i->logip)))
			{
				matchedlogrec log;
				memset(&log.logname,0,sizeof(log.logname));
				memcpy(&log.logname,j->logname,strlen(j->logname));
				
				memset(&log.logip,0,sizeof(log.logip));
				memcpy(&log.logip,j->logip,strlen(j->logip));
				
				log.logintime=j->logtime;
				log.logouttime=i->logtime;
				log.durations=i->logtime-j->logtime;
				logs->push_back(log);
				//sleep(1);
				b=1;
				logins->erase(j);
				break;
			}
			j++;
		}
		logouts->erase(i);
		i=logouts->begin();	
	}
}
//保存没有匹配的登入记录
void LogReader::saveLogins(list<logrec> *logins)
{
	//打开剩余的登入记录文件。
	int fd=open(loginsfile,O_RDWR|O_CREAT|O_TRUNC);
	if(fd==-1)
	{
		//创建文件等异常
		return;//不做任何处理
	}
	while(logins->size()>0)
	{
		list<logrec>::iterator it=logins->begin();
		logrec log=*it;
		int re=write(fd,&log,sizeof(logrec));
		logins->erase(it);
		if(re==-1)
		{
			break;//错误发生，结束写数据
		}
	}
	close(fd);
}
