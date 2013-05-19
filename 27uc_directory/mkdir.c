#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
	char comd;
	char pathCmd[256];
	umask(0002);     //set the mode mask number
	while(1){
		printf(">> ");
		scanf(" %c",&comd);
		if(comd=='q') break;
		
		switch(comd){
		case 'm':
			printf("input your path which you want to create\n>>");
			scanf("%s",pathCmd);
			if(mkdir(pathCmd,0777)<0)
				perror(pathCmd);
			break;
		case 'r':
			printf("input your path to deltet\n>>");
			scanf("%s",pathCmd);
			if(rmdir(pathCmd)<0)   //rmdir() use to delete directory
				perror(pathCmd);
			break;
		case 'c':
			printf("input your path to set current path\n>>");
			scanf("%s",pathCmd);
			if(chdir(pathCmd)<0)
				perror(pathCmd);
			break;
		case '!':
			printf("input your command\n>>");
			scanf(" %[^\n]",pathCmd);
			system(pathCmd);
			break;
		case 'g':
			getcwd(pathCmd,sizeof(pathCmd));
			puts(pathCmd);
			break;
		default:
			printf("Unknow command\n");
			scanf(" %*[^\n]");   //丢弃一整行
			break;
		}
	}
        return 0;
}
