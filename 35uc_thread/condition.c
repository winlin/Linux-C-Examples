/*
 *使用条件变量实现线程间等待
 *此例演示了条件变量使用过程中调用的注意问题
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//mutex initlize
pthread_cond_t c=PTHREAD_COND_INITIALIZER;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t n=PTHREAD_MUTEX_INITIALIZER;

void* threadFunc(void* arg)
{
	pthread_mutex_lock(&m);  //互斥量加锁
	//DO WAHT YOU WANT HERE
	printf("thread %u initlize over.\n",pthread_self());
	++(*(int*)arg);
	pthread_cond_signal(&c);   //释放一个信号量，发送条件变量的一个信号给pthread_cond_wait()
	pthread_mutex_unlock(&m); //互斥量解锁
	sleep(5);
	printf("thread %u over\n",pthread_self());
	return arg;
}

int main()
{
	int count=0;
	int i;
	pthread_t ids[3]={0};

	pthread_mutex_lock(&m);
	for(i=0;i<3;++i){
		pthread_create(&ids[i],NULL,threadFunc,&count);
	}
	printf("All thread create over.\n");
	pthread_mutex_unlock(&m);

	//要保证在调用pthread_cond_wait()之前，一定要要保证应经加锁，
	//保证只有一个对pthread_cond_wait的互斥调用。
	pthread_mutex_lock(&n);   //主线程和子线程可以不用同一个互斥锁
	do{
		pthread_cond_wait(&c,&m);  //wait会先解锁，等待条件变量的信号，信号到来后再加锁
		printf("already initilized threads is %d\n",count);
	}while(count!=3);
	pthread_mutex_unlock(&n);
	
	pthread_mutex_destroy(&m);
	pthread_mutex_destroy(&n);
	pthread_cond_destroy(&c);

	printf("所有的线程已经初始化完成.\n");
        //主线程做自己的工作
	//......
	
	
	for(i=0;i<3;++i){
		pthread_join(ids[i],NULL);
	}
		
	return 0;
}
