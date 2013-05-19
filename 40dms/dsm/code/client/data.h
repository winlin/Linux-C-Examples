#ifndef DATA_H
#define DATA_H
#include <sys/types.h>

struct log_rec{
	char username[32];
	pid_t pid;
	short log_type;
	int log_time;
	char log_ip[257];
};

struct log_match_rec{
	char username[32];
	int login_time;
	int logout_time;
	int durations;
	char log_ip[257];
};

#endif
