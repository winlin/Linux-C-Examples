#include <stdio.h>
/*
 *在C语言中传递二维数组时，往往不传递数组个数，而是传递一个空指针表示数组结束
 */
int main(int argc,char* argv[],char* env[])
{
	int i;
	for(i=0;env[i]!=NULL;++i)
		printf("%d:%s\n",i+1,env[i]);
        return 0;
}
