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
	
	printf("input name ,age and 消息型号\n");
	scanf("%s%d%ld",m.p.name,&m.p.age,&m.no);
	if(msgsnd(mid,&m,sizeof(m),0)<0){
		perror("msgsnd");
		return -1;
	}
	else
		puts("Send Successfully.\n");
	
	
	return 0;
}
