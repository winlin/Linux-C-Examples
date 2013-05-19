/*
 *使用dlopen等函数，自动加载动态库
 *gcc test.c -ldl -ldy -L.
 *dlopen等函数需要libdl.so库文件，所以也要加载它 -ldl
 */
#include <stdio.h>
#include <dlfcn.h>
#include "lib.h"

int main(int argc,char* argv[])
{
	void* handle=dlopen("./libdy.so",RTLD_NOW);
	if(!handle){
		printf("dlopen %s\n",dlerror());
		return -1;
	}
	void (*ph)(const char*)=dlsym(handle,"hello");
	typedef const char* (*PFUN)(int);
	
	PFUN pg=dlsym(handle,"getname");
	int (*pa)(int)=dlsym(handle,"add");
	int *pv=dlsym(handle,"var");
	const char* err=dlerror();
	if(err){
		printf("error: %s\n",err);
		return -1;
	}
	ph("winlin");
	printf("500: %s\n",pg(500));
	pa(10);pa(20);
	printf("var=%d \n",*pv);
	*pv=123;
	pa(80);
	printf("var=%d \n",*pv);

	dlclose(handle);
	
	return 0;
}
