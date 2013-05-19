/*
 *使用信号量实现线程间互斥
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* List=NULL;

void* threadFunc(void* arg)
{
	pthread_mutex_init(&m);
	while(1){
		if()
	}
	pthread_mutex_des
}

void* func(void*)
{
	if
}

int main()
{   

	return 0;
}
