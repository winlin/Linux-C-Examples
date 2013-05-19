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
//	struct Person a;
//	a.set = set;
//	a.show = show;
//	a.set(&a, "quange", 40);
//	a.show(&a);
	int id = msgget(0x1234, IPC_CREAT|0600);
	if(id<0){perror("msgget");return 1;}
	struct Msg m;
	printf("请输入姓名、年龄和通道号:");
	scanf("%s%d%u", &m.p.name,&m.p.age,&m.no);
	if(msgsnd(id,&m,sizeof(m),0)<0)
		perror("msgsnd");
	else
		puts("发送成功");
	return 0;
}

