#ifndef SERVER_H
#define SERVER_H
#include "data.h"

class Server{
public:
	void acceptRec();
private:
	int sockfid;
};

#endif
