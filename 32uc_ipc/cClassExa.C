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

int main(int argc,char* argv[])
{
	struct Person a;
	a.set=set;
	a.show=show;
	a.set(&a,"winlin",23);
	a.show(&a);
	return 0;
}
