/*
 *线程共享main函数的数据
 *线程和main函数共享同一个虚拟地址空间，但是他们有自己的栈空间
 *但是，由于在同一个虚拟地址空间中，所以，是可以互访的。
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thrOne(void* p)
{
	printf("p=%p  val=%d\n",p,*(int*)p);
	return NULL;
}

void* thrTwo(void* q)
{
	printf("q=%p  val=%g\n",q,*(double*)q);
	return NULL;
}
int main(int argc,char* argv[])
{
	int x=123;
	double y=456.789;
	
	pthread_t id1,id2;
	printf("&x=%p\n",&x);
	pthread_create(&id1,NULL,thrOne,&x);
	
	printf("&y=%p\n",&y);
	pthread_create(&id2,NULL,thrTwo,&y);

        //sleep(3);  //main函数不会自动等待线程的执行
	//等待线程的结束
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
	return 0;
}
