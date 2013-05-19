#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int isleap(int y)
{
	if(y%400==0||y%4==0&&y%100!=0)
		return 1;
	else
		return 0;
}
void welcome()
{
	puts("happy weekend!");
}
int getid(const char* name)
{
	struct passwd* p = getpwnam(name);
	if(p==NULL) return -1;
	return p->pw_uid;
}
const char* timestr(struct tm* p)
{
	static char buf[200];
	strftime(buf, sizeof(buf), "%F %T", p);
	return buf;
}
char* itoa(int val, char* buf, int size)
{
	sprintf(buf, "%d", val);
	return buf;
}

