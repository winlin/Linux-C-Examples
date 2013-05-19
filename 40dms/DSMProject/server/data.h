#ifndef DATA_H
#define DATA_H
#include <cstdlib>
#include <cstdio>
struct logrec
{	
	char 		logname[32];
	pid_t  	pid;
	time_t   logtime;
	char  	logip[257]; 
};
struct matchedlogrec
{
	char 	logname[32];
	time_t  	logintime;
 	time_t  	logouttime;
	int  	durations;
	char	logip[257];
};

struct logdata : matchedlogrec
{
	char labip[32];
};
#endif
