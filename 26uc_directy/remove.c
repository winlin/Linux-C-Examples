/*
 *remove()不可以删除非空目录，所以要实现非空目录删除要循环的进入目录删除
 */
#include <stdio.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	if(argc==1){
		printf("Usage: %s file ",*argv);
		return 0;
	}
	int i;
	for(i=1;i<argc;++i){
		if(remove(argv[i])==-1){
			//	chdir(argv[i]);
			printf("Delete %s failed.\n",argv[i]);
		}
		else
			printf("Delete %s succeed.\n",argv[i]);
		
	}
		
        return 0;
}
