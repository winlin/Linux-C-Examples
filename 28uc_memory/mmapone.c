/*mmap()匿名映射*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{
	int* p=mmap(NULL,10*sizeof(int),PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,0,0);
	if(p==MAP_FAILED){
		perror("mmap():");
		exit(-1);
	}
	printf("%p\n",p);
	int i=0;
	for(i=0;i<10;++i)
		p[i]=11+i;
	for(i=0;i<10;++i)
		printf("%d ",p[i]);
	printf("\n");
	munmap(p,10*sizeof(int));
        return 0;
}
