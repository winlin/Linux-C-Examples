#include"logreader.h"
void logreader::readlog(list<logmatchrec> *matches){
	char backfilename[30]={0};
	list<logrec> logins;
	list<logrec> logouts;
	backlogfile(backfilename);
	readlogins(&logins);
	readbacklogfile(backfilename,&logins,&logouts);
	matchlogs(&logins,&logouts,matches);
	savelogins(&logins);

}
void logreader::backlogfile(char *backfilename)
{
	cout<<"1.hello"<<endl;
}
void logreader::readlogins(list<logrec> *logins)
{
	cout<<"2.hello"<<endl;
}
void logreader::readbacklogfile(char *backfilename,list<logrec> *logins,
		list<logrec> *logouts)
{
	cout<<"3.hello"<<endl;
}
void logreader::matchlogs(list<logrec> *logins,list<logrec> *logouts,
		list<logmatchrec> *matches)
{
	cout<<"4.hello"<<endl;
}
void logreader::savelogins(list<logrec> *logins)
{
	cout<<"5.hello"<<endl;
}
