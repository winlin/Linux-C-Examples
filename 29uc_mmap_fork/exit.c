#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void furong()
{
	puts("再见芙蓉");
}
void fengjie()
{
	puts("永别了凤姐");
}
void myexit(const char* msg, int val)
{
	puts(msg);
	_exit(val);//exit(val);
}
int main()
{
	atexit(furong);//登记，不是现在调用而是程序结束时调用
	atexit(fengjie);//登记，不是现在调用而是程序结束时调用
	printf("登记完毕\n");
	sleep(5);
	printf("ready to terminate\n");
	myexit("call myexit", 0);
	printf("you cannot see me.\n");
	return 0;
}

