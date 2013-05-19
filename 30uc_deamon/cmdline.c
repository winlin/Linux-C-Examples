#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int i=0;
	printf("pid=%d,argc:%d\n", getpid(),argc);
	while(i<argc){
		printf("argv[%d]=%s\n", i, argv[i]);
		++i;
	}
	return 0;
}
