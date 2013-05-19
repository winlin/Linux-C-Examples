/*
 *演示线程互斥
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;
Node* head=NULL;

pthread_mutex_t m;

void* workFunc(void* param)
{
	while(1){
		//intf("%u\n",pthread_self());
		pthread_mutex_lock(&m);   //加锁
		if(!head)
			break;
		Node* p=head;
		head=head->next;
		pthread_mutex_unlock(&m); //解锁
		
		printf("number is %d\n",p->data);
		free(p);
		p=NULL;
		sleep(1);
	}
	return NULL;
}
void addWork(int data)
{
	Node* p=malloc(sizeof(Node));
	p->data=data;
	p->next=NULL;
	Node** t=&head;
	while(*t!=NULL){
		t=&((*t)->next);  //attention
	}
	*t=p;
}

int main(int argc,char* argv[])
{
	pthread_mutex_init(&m,NULL);
	int i;
	addWork(11);
	addWork(22);
	addWork(33);
	addWork(44);
	
	pthread_t ids[3]={0};
	for(i=0;i<3;++i){
		pthread_create(ids+i,NULL,workFunc,NULL);
	}

	sleep(20);
	pthread_mutex_destroy(&m);
	return 0;
}
