#ifndef DATA_H
#define DATA_H
#include <stdlib.h>
#include <sys/types.h>
	struct logrec{
		char username[32];
		pid_t pid;
		short logtype;
		int logtime;
		char ip[257];
	};
	struct logmatchrec{
		char username[32];
		pid_t pid;
		short logtype;
		int logintime;
		int logouttime;
		int durations;
		char ip[257];
	};
#endif
