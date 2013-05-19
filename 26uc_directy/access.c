/*
 *access()可以用来判断文件是否存在以及文件的访问权限
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	if(argc==1){
		printf("Usage: %s path\n",*argv);
		exit(0);
	}
	int i;
	for(i=1;i<argc;++i){
		if(!access(argv[i],F_OK)){
			printf("%s : ",argv[i]);
			printf("%c",access(argv[i],R_OK)?'-':'R');
			printf("%c",access(argv[i],W_OK)?'-':'W');
			printf("%c\n",access(argv[i],X_OK)?'-':'X');
		}
		else
			printf("%s不存在\n",argv[i]);
	}
        return 0;
}
