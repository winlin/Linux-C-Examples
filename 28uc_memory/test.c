#include <stdio.h>

int main(int argc,char* argv[])
{
	int i;
	printf("argc=%d",argc);
	for(i=1;i<argc;++i)
		printf("%s\n",argv[i]);
	
        return 0;
}
