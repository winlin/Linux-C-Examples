     #include "logreader.h"
	 #include <list>
	 #include <iostream>
	 using namespace std;
		/*这个函数负责把文件变成要发送的数据集合*/
		void logreader:: readlog(list<logmatchrec> *matches){
			char backfilename[30];
			list<logrec> logins;
			list<logrec> logouts;
		    backlogfile(backfilename);
            readlogins(&logins);
			readbacklogfile(backfilename,&logins,&logouts);
            matchlogs(&logins,&logouts,matches);
			savelogins(&logins);
		}
	
		/*备份 把wtmpx按照日期备份 再把wtmpx清空 得到备份的文件名*/
		void logreader:: backlogfile(char *backfilename){
		    cout<<"1备份"<<endl;
		}
		/*读取上次没有匹配的记录*/
		void logreader:: readlogins(list<logrec> *logins){
		    cout<<"2读取上次没有匹配的记录"<<endl;
		}
		/*读取备份的日志文件,得到登录集合和登出集合*/
		void logreader:: readbacklogfile(char* backfilename,list<logrec> *logins,list<logrec> *logouts){
		    cout<<"3读取备份的日志文件,得到登录集合和登出集合"<<endl;
		}
		/*用登出集合去登录集合中匹配*/
		void logreader:: matchlogs(list<logrec> *logins,list<logrec> *logouts,list<logmatchrec> *matchs){
		    cout<<"4用登出集合去登录集合中匹配"<<endl;
		}
		/*保存没有匹配成功的登录记录*/
		void logreader:: savelogins(list<logrec> *logins){
		   cout<<"5保存没有匹配成功的登录记录"<<endl;
		}
		

