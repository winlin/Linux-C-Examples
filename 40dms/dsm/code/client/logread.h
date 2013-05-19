#ifndef LOGREAD_H
#define LOGREAD_H
#include "data.h"
#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;

struct log_rec;
struct log_match_rec;

const string WTMPX="/var/adm/wtmpx";

class LogRead{
public:
	LogRead();
	
	void readlog();
	void sendlog();
	void showinfo();
private:
	
	void bakeuplog();
	void readleft();
	void getlists();
	void matchlist();
	void saveleft();

private:
	string  leftlogs;
	string  bakeupdir;
	string  bakefile;
	list<log_rec> login_list;
	list<log_rec> logout_list;
	list<log_match_rec> match_list;

	int sumlogins;
	int sumlogouts;
	int matchrecs;
	int unmatchlogins;
	int unmatchlogouts;
};

#endif
