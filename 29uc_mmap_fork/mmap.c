#include <stdio.h>
#include <sys/mman.h>

int main()
{
	int* p = mmap(
		NULL,//(void*)0xb7f88000,
		10*sizeof(int),
		PROT_READ|PROT_WRITE,
		MAP_PRIVATE|MAP_ANONYMOUS,
		0,0);
	printf("p=%p\n", p);
	if(p==MAP_FAILED){
		perror("Ê§°Ü");
		return -1;
	}
	int i;
	for(i=0; i<10; i++)
		p[i] = 11+i;
	for(i=0; i<10; i++)
		printf("%d ", p[i]);
	printf("\n");
	munmap(p, 10*sizeof(int));
	return 0;
}

