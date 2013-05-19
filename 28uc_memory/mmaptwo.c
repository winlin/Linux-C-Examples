/*把文件映射到内存*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	umask(0000);
	int fd=open("map.file",O_CREAT|O_RDWR,0666);
	ftruncate(fd,1000);
	char* p=mmap(NULL,1000,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		perror("mmap()");
		exit(-1);
	}
	/*
	 *s :store data
	 *g :get data
	 *q :quit
	 */
	char cmd;
	while(1){
		printf("input your choice\n");
		scanf(" %c",&cmd);
		if(cmd=='q')
			break;
		if(cmd=='s'){
			scanf("%s",p);
			scanf("%*c");
		}
		if(cmd=='g'){
			puts(p);
		}
	}
	munmap(p,1000);
	
        return 0;
}
