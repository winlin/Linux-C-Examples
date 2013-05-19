#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

void hello(const char* name)
{
	printf("hello, dear %s\n", name);
}
const char* getname(int id)
{
	struct passwd* p = getpwuid(id);
	if(p==NULL) return NULL;
	return p->pw_name;
}
int var=0;
int add(int n)
{
	var += n;
	return var;
}

