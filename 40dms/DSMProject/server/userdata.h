#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H
#include "data.h"
#include <deque>
#include <pthread.h>
using namespace std;
class UserData
{
	private:
		deque<logdata> data;
		pthread_mutex_t mutex;
		pthread_cond_t cond;
	public:
		UserData();
		~UserData();
		void push_data(logdata num);
		logdata pop_data();
		int getsize();
};
#endif
