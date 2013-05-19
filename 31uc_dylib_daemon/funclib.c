#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int isleap(int y)
{
	return (y%400==0||(y%4==0&&y%100!=0));
}

void welcome()
{
	puts("welocme to share object.\n");
}

int getid(const char* name)
{
	struct passwd* p=getpwnam(name);
	if(!p)
		return -1;
	return p->pw_uid;
	
}

const char* timestr(struct tm* p)
{
	static char buf[128];
	strftime(buf,sizeof(buf),"%F %T",p);
	return buf;
}

char* itoa(int val,char buf[],int size)
{
	sprintf(buf,"%d",val);
	return buf;
}
