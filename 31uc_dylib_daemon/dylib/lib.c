#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

void hello(const char* name)
{
	printf("hello %s\n",name);
}
const char* getname(int id)
{
	struct passwd* p=getpwuid(id);
	if(!p)
		return NULL;
	return p->pw_name;
}

extern int var;
int var=0;

int add(int n)
{
	return (var+n);
}
