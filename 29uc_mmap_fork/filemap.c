#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	umask(0);
	int fd = open("map.file", O_RDWR|O_CREAT, 0666);
	ftruncate(fd, 1000);
	char* p = mmap(NULL,1000,
		PROT_READ|PROT_WRITE,
		MAP_SHARED|MAP_FILE,
		fd,0);
	close(fd);
	if(p==MAP_FAILED){
		perror("Ê§°Ü");
		return 1;
	}
	//s data|g|q
	for(;;){
		char cmd;
		printf("s data|g|q:");
		scanf(" %c", &cmd);
		if(cmd=='q') break;
		if(cmd=='s') scanf("%s", p);
		else if(cmd=='g') puts(p);
		else puts("ÎÞÐ§");
	}
	munmap(p, 1000);
}

