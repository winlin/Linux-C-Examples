#include "clientaccepter.h"
#include "dmsexception.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "dmsdao.h"
#include "userdata.h"
#include <iostream>
using namespace std;
UserData  udata; //全局的放接收数据的容器
void* receviedata(void *thobj)
{
	threadp* smfd=(struct threadp*)thobj;
	cout<<"mfd"<<(smfd->cfd)<<endl;
	int cfd=smfd->cfd;
	char *cip=smfd->cip;
	struct matchedlogrec log;
	//每次满304字节，上面log数据满，就保存到数据库		
	size_t size=0;//同时记录结构体存放的偏离位置,当到达304的时候，存放下一个结构体
	size_t len=sizeof(struct matchedlogrec);//结构体总长度	

	while(1)
	{
		//线程执行处
		char  data[sizeof(struct matchedlogrec)];//每次接受的最大字节数
		//因为使用的是TCP，每次接受的数据未必是一个完整的结构,所以要确保304字节的完整性
		size_t t=recv(cfd,&data,sizeof(data),0);
		
		if(t<=0 || t==-1)//表示网络断掉了或者接受失败
		{	
			break;//采集任务结束，终止本次采集
		}
		if(t>0)//接受到数据
		{
			if(t<len-size)//未满
			{	
				memcpy(((char*)&log)+size,data,t);//注意指针运算的基本单位
				size+=t;	
			}
			else//满
			{
				memcpy(((char*)&log)+size,data,len-size);//剩余部分放下一个记录
				//cout<<log.logname<<":"<<log.logip<<endl;
				//传递给DAO对象处理-保存
				struct logdata rdata;
				memcpy(&rdata,&log,sizeof(log));
				strcpy(rdata.labip,cip);
				//mdao.save(rdata);  现在不在这里放入数据库
				udata.push_data(rdata);
				cout<<cfd<<":"<<cip<<":"<<rdata.logname<<endl;
				if(t-len+size>0)
				{
					memcpy(&log,data+len-size,t-len+size);
					//由于目标与缓冲等长，所以这里不用判定是否够长
					size=t-len+size;
				}
				else
				{
					size=0;
				}
			}		
		} 
	}
	close(cfd);
	cout<<"采集结束"<<endl;
    return thobj;

}
class  DataReciveThread  //这个线程只管接收数据 相当于生产者
{
 public:  //启动创建接收数据的线程的函数
      void  start(threadp *tp){
          pthread_t threadid;
          pthread_create(&threadid,NULL,receviedata,(void*)tp);
       }
};
void * savedata(void *obj){
	DMSDAO  mdao;  //创建存入数据的对象
	char  userp[30]="openlab/open123";
	mdao.connect(userp);
	int i=0;
	while(1){		
		if(i++%150==0) mdao.commit();  //150次数据统一提交  不到150线程结束时提交
	    mdao.save(udata.pop_data());
	    if(udata.getsize()==0) break;  //如果发现没有数据  则结束这个线程
	}
	mdao.close();
}
class  DataCustomerThread  //这个线程只管把数据放入数据库 相当于消费者
{
 public:  //启动创建接收数据的线程的函数
      void  start(){
          pthread_t threadid;
          pthread_create(&threadid,NULL,savedata,NULL);
       }
};
//构造器
ClientAccepter::ClientAccepter():port(9999)
{
}
//设置服务器端口，构造器默认初始化为9999
void ClientAccepter::setPort(unsigned short pt)
{
	port=pt;
}
//初始化服务器
int  ClientAccepter:: initSocket()
{
	//创建Socket服务器
	fd=socket(PF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		throw DMSException("服务器Socket建立错误！");
	}
	//绑定地址
	struct sockaddr_in addr={};
	addr.sin_family=PF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	int re=bind(fd,(struct sockaddr*)&addr,sizeof(sockaddr_in));
	if(re==-1)
	{
		throw DMSException("服务器Socket绑定错误！");
	}
	//监听
	re=listen(fd,10);
	if(re==-1)
	{
		throw DMSException("服务器Socket监听错误！");
	}
	return fd;
}


int main(){
  ClientAccepter  serverm;
  int fd= serverm.initSocket();
  while(1){
	
    struct sockaddr_in addr={};
	socklen_t len=sizeof(struct sockaddr_in);
	int cfd=accept(fd, (struct sockaddr *)&addr, &len);
	cout<<"cfd"<<cfd<<endl;
	if(cfd==-1)
	{
		throw DMSException("接受客户连接错误！");
	}
	char *cip=inet_ntoa(addr.sin_addr);
    cout<<"cip"<<cip<<endl;
	//在这里创建 接收数据的线程  把得到的客户端网络描述符cfd
	//和客户端的服务器ip传入到线程中
	 struct  threadp  tp;
	 tp.cfd=cfd;
	 strcpy(tp.cip,cip);
	 DataReciveThread  drt;  //创建生产者 接收数据
	 cout<<"本次采集开始"<<endl;
	 drt.start(&tp); 
	 DataCustomerThread  dct; //创建消费者  存入数据到数据库
	 dct.start();
  }
 
}
