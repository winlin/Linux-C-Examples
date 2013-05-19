#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct Person{
	char name[20];
	int age;
//	void (*set)(struct Person*this,const char*name, int age);
//	void (*show)(struct Person*this);
};
//void set(struct Person* this, const char* name, int age)
//{
//	strcpy(this->name,name);
//	this->age = age;
//}
void show(struct Person* this)
{
	printf("%s : %d\n", this->name, this->age);
}
struct Msg{
	long no;
	struct Person p;
};
int main()
{
	int id = msgget(0x1234, IPC_CREAT|0600);
	if(id<0){perror("msgget");return 1;}
	struct Msg m;
	printf("请输入通道号:");
	scanf("%u", &m.no);
	if(msgrcv(id,&m,sizeof(m),m.no,0)<0)
		perror("msgsnd");
	else{
		printf("来自通道%d, 姓名%s, 年龄%d\n", m.no, m.p.name, m.p.age);
	}
	return 0;
}

