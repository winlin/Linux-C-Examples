/*
 *该程序的作用类似与ls -l
 *stat()用于查询文件/目录的的具体文件描述信息 S_ISREG在man 2 stat
 *time(NULL)可以获得time_t类型的结构
 *localtime()可以把time_t类型转化成struct tm*
 *strftime()可以把struct tm*类型转化成格式化的字符串
 *getpwuid()可以根据用户id返回描述用的信息
 *getgrgid()可以根据组id反或描述组的信息
 */
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char* strmode(mode_t m)
{
	static char a[11]={0};
	if(S_ISREG(m)) a[0]='-';
	else if(S_ISDIR(m)) a[0]='d';
	else if(S_ISFIFO(m)) a[0]='p';
	else if(S_ISCHR(m))  a[0]='c';
	else if(S_ISBLK(m))  a[0]='b';
	else if(S_ISLNK(m))  a[0]='l';
	
	a[1]= m&S_IRUSR?'r':'-';
	a[2]= m&S_IWUSR?'w':'-';
	a[3]= m&S_IXUSR?'x':'-';
	a[4]= m&S_IRGRP?'r':'-';
	a[5]= m&S_IWGRP?'w':'-';
	a[6]= m&S_IXGRP?'x':'-';
	a[7]= m&S_IROTH?'r':'-';
	a[8]= m&S_IWOTH?'w':'-';
	a[9]= m&S_IXOTH?'x':'-';
	return a;
}

char* strDate(time_t m)
{
	struct tm* p=localtime(&m);
	static char time[100];
	strftime(time,sizeof(time),"%b %d %H:%M",p);
	return time;
}

int main(int argc,char* argv[])
{
	if(argc<2){
		printf("Usage %s file \n",argv[0]);
		return 0;
	}
	struct stat s;
	int i;
	for(i=1;i<argc;++i){
		if(stat(argv[i],&s))
			perror(argv[i]);   //printf("%m") error message
		else{
			struct passwd* p=getpwuid(s.st_uid);
			struct group* pg=getgrgid(s.st_gid);
			printf("%10s %5d %6s %6s %8d  %12s  %s\n",
			       strmode(s.st_mode),s.st_nlink,
			       p->pw_name,pg->gr_name,s.st_size,
			       strDate(s.st_mtime),argv[i]);
		}
	}	
        return 0;
}
