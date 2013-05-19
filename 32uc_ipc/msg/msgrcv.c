#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Person{
	char name[20];
	int age;
	void (*set)(struct Person* this,const char* name,int age);
	void (*show)(struct Person* this);
};

void set(struct Person* this,const char* name,int age)
{
	strcpy(this->name,name);
	this->age=age;
}

void show(struct Person* this)
{
	printf("%s %d\n",this->name,this->age);
}

struct Msg{
	long no;
	struct Person p;
};

	
int main(int argc,char* argv[])
{
	/*struct Person a;
	a.set=set;
	a.show=show;
	a.set(&a,"winlin",23);
	a.show(&a);*/

	struct Msg m;
	int mid;
	printf("请输入消息队列的id\n");
	scanf("%d",&mid);
	
	printf("请输入要接收信号的类型 \n");
	int mtype=0;
	scanf("%d",&mtype);
	
	if(msgrcv(mid,&m,sizeof(m),mtype,IPC_NOWAIT)<0){
		perror("msgrcv");
		return -1;
	}
	else{
		printf("消息队列id：%d  消息类型： %d \n",mid,mtype);
		printf("%s,%d\n",m.p.name,m.p.age);
	}
	return 0;
}
