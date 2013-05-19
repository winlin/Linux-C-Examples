#include <stdio.h>
#include <time.h>

#include "funclib.h"

int main()
{
	welcome();
	printf("%d\t%d\n",isleap(2011),isleap(2012));
	printf("winlin uid=%d\n",getid("winlin"));
	time_t now=time(NULL);
	printf("time:%s\n",timestr(localtime(&now)));
	char buf[128];
	printf("123456:%s\n",itoa(123456,buf,sizeof(buf)));
	return 0;
}
