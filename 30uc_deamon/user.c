#include <pwd.h>
#include <string.h>
#define IN
#define OUT
int getname(int IN id, char OUT name[], int IN size)
{
	struct passwd* p = getpwuid(id);
	if(p==NULL) return -1;
	if(strlen(p->pw_name)>=size) return -1;
	strcpy(name, p->pw_name);
	return 0;
}

