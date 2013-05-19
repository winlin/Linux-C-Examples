#include <pwd.h>
#define IN
#define OUT
int getid(const char* IN name)
{
	struct passwd* p = getpwnam(name);
	if(p==0) return -1;
	return p->pw_uid;
}

