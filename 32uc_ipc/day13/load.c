#include <dlfcn.h>
#include <stdio.h>
//#include "so.h"
#include <stdlib.h>
int main()
{
	void* handle = dlopen("./lib/libso.so", RTLD_NOW);
	if(handle==NULL){
		printf("dlopen: %s\n", dlerror());
		exit(1);
	}
	void(*ph)(const char*) = dlsym(handle, "hello");
	typedef const char* (*F1)(int);
	F1 pg = dlsym(handle, "getname");
	int(*pa)(int) = dlsym(handle, "add");
	int* pv = dlsym(handle, "var");
	const char* err = dlerror();
	if(err!=NULL){
		printf("error: %s\n", err);
	}
	else{
		(*ph)("csd1106");
		printf("501: %s\n", pg(501));
		pa(10); pa(20);
		printf("var=%d\n", *pv);
		*pv = 123;
		printf("var=%d\n", pa(80));
	}
	dlclose(handle);
	return 0;
}

