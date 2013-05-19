#include "client.h"
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

/*初始化Client数据成员*/
Client::Client()
{
	bakeupdir=getenv("HOME");
	bakeupdir+="/LogDir";
	leftlogs=bakeupdir+"/leftlogs.dat";
	
	if(mkdir(bakeupdir.c_str(),0755)==-1&&errno!=EEXIST)
		printerr("Client():bake directory create failed");

	/*internet*/
	strcpy(serip,"172.0.0.1");
	serport=9999;
}

/*调用一个脚本，每小时备份wtmpx文件，并且文件名为 2011031220*/
void Client::bakeuplog()
{
	time_t nowtime;
	time(&nowtime);
	struct tm* ptm;
	ptm=localtime(&nowtime);
	char strtime[12];
	strftime(strtime,sizeof(strtime),"%Y%m%d%H",ptm);

	bakefile=strtime;
	/*执行备份脚本*/
	string strcmd="sh ./bake.sh ";
	strcmd=strcmd+WTMPX+" "+bakeupdir+"/"+bakefile;
	if(system(strcmd.c_str())==-1)
		printerr("bakeuplog():bakefile failed");
}

/*把上次未匹配的记录读取到login_list*/
void Client::readleft()
{
	int fid=open(leftlogs.c_str(),O_RDONLY);
	if(fid!=-1){
		struct stat buf;
		if(fstat(fid,&buf)){
			printerr("readleft():fstat() failed");
		}
		int count=buf.st_size/sizeof(log_rec);
		for(int i=0;i<count;++i){
			log_rec record;
			if(read(fid,&record,sizeof(record))!=sizeof(record))
				printerr("readleft():read() failed");
			
			login_list.push_back(record);
		}
		close(fid);
	}
}

/*从每次备份的文件中读取 logout/login 记录到两个链表里面*/
void Client::getlists()
{
	string file=bakeupdir+"/"+bakefile;
	int fid=open(file.c_str(),O_RDONLY);
	if(fid==-1){
		printerr("getlists():open() failed");
	}
	struct stat buf;
	if(fstat(fid,&buf)){
		printerr("getlists():fstat() failed");
	}
	int count=buf.st_size/372;
	for(int i=0;i<count;++i){
		log_rec record;
		if(read(fid,record.username,32)!=32){
			printerr("getlists():read() failed");
		}
		if(lseek(fid,4+32,SEEK_CUR)==-1){
			printerr("getlists():lseek() failed");
		}
		if(read(fid,&record.pid,sizeof(pid_t))!=sizeof(pid_t)){
			printerr("getlists():read() failed");
		}
		if(read(fid,&record.log_type,sizeof(short))!=sizeof(short)){
			printerr("getlists():read() failed");
		}
		if(lseek(fid,2+2+2,SEEK_CUR)==-1){
			printerr("getlists():lseek() failed");
		}
		if(read(fid,&record.log_time,sizeof(int))!=sizeof(int)){
			printerr("getlists():read() failed");
		}
		if(lseek(fid,4+4+20+2,SEEK_CUR)==-1){
			printerr("getlists():lseek() failed");
		}
		if(read(fid,record.log_ip,257)!=257){
			printerr("getlists():read() failed");
		}
		if(lseek(fid,1,SEEK_CUR)==-1){
			printerr("getlists():lseek() failed");
		}

		/*舍弃掉用户名第一个为'.'的记录*/
		if(record.username[0]=='.')
			continue;
		
		if(record.log_type==7)
			login_list.push_back(record);
		else if(record.log_type==8)
			logout_list.push_back(record);
	}
	close(fid);
	sumlogins=login_list.size();
	sumlogouts=logout_list.size();
}

/*匹配记录*/
void Client::matchlist()
{
	list<log_rec>::iterator it_in=login_list.begin();
	list<log_rec>::iterator it_out;
	
	for(;it_in!=login_list.end();++it_in){
		for(it_out=logout_list.begin();it_out!=logout_list.end();++it_out){
			if(strncmp(it_in->username,it_out->username,32)==0
			   &&it_in->pid==it_out->pid
			   &&strncmp(it_in->log_ip,it_out->log_ip,257)==0){
				
				log_match_rec match_rec;
				strncpy(match_rec.username,it_in->username,32);
				match_rec.login_time=it_in->log_time;
				match_rec.logout_time=it_out->log_time;
				match_rec.durations=it_out->log_time-it_in->log_time;
				strncpy(match_rec.log_ip,it_in->log_ip,257);
				
				match_list.push_back(match_rec);
				login_list.erase(it_in);
				logout_list.erase(it_out);
				/*防止删除最后一个时再加加时越界*/
				--it_in;
				--it_out;
				/*不再向下匹配*/
				break;
			}	
		}
	}
	matchrecs=match_list.size();
	unmatchlogins=login_list.size();
	unmatchlogouts=logout_list.size();
}

/*把未匹配的 login 记录保存到文件*/
void Client::saveleft()
{
	if(login_list.size()){
		int fid=open(leftlogs.c_str(),O_CREAT|O_TRUNC|O_WRONLY,0755);
		if(fid==-1)
			printerr("saveleft():open failed");
		list<log_rec>::iterator it;
		for(it=login_list.begin();it!=login_list.end();++it){
			struct log_rec plog;
			strncpy(plog.username,it->username,32);
			plog.pid=it->pid;
			plog.log_type=it->log_type;
			plog.log_time=it->log_time;
			strncpy(plog.log_ip,it->log_ip,257);
			
			if(write(fid,&plog,sizeof(plog))!=sizeof(plog))
				printerr("saveleft():write() failed");

			login_list.erase(it);
		}
		close(fid);
	}
}

void Client::showinfo()
{
	/*
	if(match_list.size()){
		list<log_match_rec>::iterator it;
		for(it=match_list.begin();it!=match_list.end();++it){
			cout<<"Name:"<<it->username<<endl<<"IP:"<<it->log_ip<<endl;
		}	
	}
	else
		cout<<"match login list is empty"<<endl;
	*/
	cout<<"========================================"<<endl;
	cout<<"Sum login records is "<<sumlogins<<endl;
	cout<<"Sum logout records is "<<sumlogouts<<endl;
	cout<<"Unmatch login records is "<<unmatchlogins<<endl;
	cout<<"Unmatch logout records is "<<unmatchlogouts<<endl;
	cout<<"Match records is "<<matchrecs<<endl;
	cout<<"========================================"<<endl;
}

void Client::readlog()
{
	bakeuplog();
	readleft();
	getlists();
	matchlist();
	saveleft();
}

void Client::sendlog()
{
	int serfid=socket(AF_INET,SOCK_STREAM,0);
	if(serfid==-1)
		printerr("socket() failed");

	sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(serport);
	inet_aton(serip,&saddr.sin_addr);

	socklen_t addrlen=sizeof(saddr);
	if(bind(serfid,(sockaddr*)&saddr,addrlen)==-1){
		printerr("bind()");
	}

	if(connect(serfid,(sockaddr*)&saddr,addrlen)==-1){
		printerr("bind()");
	}

	/*send the match log record*/
	list<log_match_rec>::iterator it;
	for(it=match_list.begin();it!=match_list.end();++it){
		int rc;
		int byte;
		int len=sizeof(*it);
		for(byte=0;byte<len;byte+=rc){
			rc=send(serfid,byte+&(*it),len-byte,MSG_NOSIGNAL);
			if(rc<0&&errno!=EINTR){
				printerr("send() failed");
			}
		}
		match_list.erase(it);
	}
	
	close(serfid);
}
