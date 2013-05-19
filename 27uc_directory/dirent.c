#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc==1)
		argv[1]=".";
	DIR* pd=opendir(argv[1]);
	if(pd==NULL){
		perror(argv[1]);
		return -1;
	}
	chdir(argv[1]);
	struct dirent* pe;
	struct stat s;
	while((pe=readdir(pd))!=NULL){
		stat(pe->d_name,&s);
		printf("%-12s\t%c\n",
		       pe->d_name,S_ISDIR(s.st_mode)?'d':'-');
		
	}
	closedir(pd);
        return 0;
}
