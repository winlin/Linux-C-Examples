#ifndef _FUNCLIB_H_
#define _FUNCLIB_H_   1

#include <time.h>

int isleap(int year);
void welcome();
int getid(const char* name);
const char* timestr(struct tm* p);
char* itoa(int val,char buf[],int size);

#endif

	
