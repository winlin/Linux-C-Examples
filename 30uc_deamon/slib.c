#include <stdio.h>
#include <stdlib.h>
#include "id.h"
#include "user.h"

int main()
{
	char buf[100];
	if(getname(0, buf, sizeof(buf))==-1){exit(-1);}
	int id = getid("soft01");
	if(id==-1){exit(-1);}
	printf("%s\n%d\n",buf,id);
}

