#include <stdio.h>
#include <stdlib.h>
/*env是指全局性的使用export的环境变量*/
int main(int argc,char* argv[],char* env[])
{
	if(argc==1){
		printf("%s 环境变量名\n",*argv);
		return 0;
	}
	char *p=getenv(argv[1]);
	if(p)
		printf("%s\n",p);
	else{
		puts("环境变量不存在!");
		puts("是否想设置该环境变量(y/n)?");
		char t;
		scanf("%c",&t);
		if(t=='y'){
			char str[]={"1234567890"};
			setenv(argv[1],str,0);
			p=getenv(argv[1]);
			/*设置的环境变量在本函数内是可见的，但是并没有添加到全局中*/
			printf("%s\n",p);
		}
	}
	/*注意，设置的环境变量只有export以后，才可以存放于全局的环境变量*/
	int i;
	for(i=0;env[i]!=NULL;++i)
		printf("%d:%s\n",i+1,env[i]);
        return 0;
}
