/*
 *time()返回的是距1900年的共有多少秒
 *localtime()返回分离格式的时间格式struct tm，然后自己再转换输出
 *strftime()可以用于把struct tm格式的时间转换成我们需要的特定格式的时间字符串
 *mktime()可以把一个struct tm格式的时间转换成一个int的形式
 */
#include <stdio.h>
#include <time.h>
int main()
{
	time_t t1,t2;
	t1=time(&t2);
	printf("%u \t %u\n",t1,t2);

	printf("%s\n",ctime(&t1));

	struct tm* p=localtime(&t1);  //gmtime()
	printf("%d-%02d-%02d %d %02d:%02d:%02d\n",
	       p->tm_year+1900,
	       p->tm_mon+1,
	       p->tm_mday,
	       p->tm_wday,
	       p->tm_hour,
	       p->tm_min,
	       p->tm_sec);

	char time[100];
	strftime(time,sizeof(time),"%F %w %T",p);
	printf("%s\n",time);
	return 0;
}
