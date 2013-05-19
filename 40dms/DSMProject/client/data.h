#ifndef DATA_H
#define DATA_H
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
#endif
