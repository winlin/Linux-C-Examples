#include <stdio.h>
#include <time.h>
#include "dll.h"

int main()
{
	welcome();
	printf("2011:%d, 2012:%d\n",isleap(2011),isleap(2012));
	printf("soft01:%d\n", getid("soft01"));
	time_t now = time(NULL);
	printf("time:%s\n",timestr(localtime(&now)));
	char buf[100];
	printf("1234543:%s\n", itoa(1234543,buf,sizeof(buf)));
	return 0;
}

