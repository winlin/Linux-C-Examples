#ifndef DATA_H
#define DATA_H
#include<sys/types.h>
typedef struct{
	char username[32];
	pid_t pid;
	short logtype;
	int logtime;
	char ip[257];
}logrec;

typedef struct{
	char username[32];
	pid_t pid;
	int logintime;
	int logouttime;
	int durations;
	char ip[257];
}logmatchrec;
#endif
