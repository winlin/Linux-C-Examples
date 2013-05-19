#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

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

static int display_info(const char* fpath,const struct stat*sb,int tflag)
{
	struct passwd* p=getpwuid(sb->st_uid);
	struct group* pg=getgrgid(sb->st_gid);
	printf("%10s %3ld %6s %6s %7jd  %12s  %-40s\n",
	       strmode(sb->st_mode),(long)sb->st_nlink,
	       p->pw_name,pg->gr_name,
	       (intmax_t)sb->st_size,
	       strDate(sb->st_mtime),fpath);
	return 0;
}
int main(int argc,char* argv[])
{
	if(argc<1){
		printf("Usage: %s file[path][file]... \n",argv[0]);
		return 0;
	}
	if(argc==1){
		argv[1]=".";
		++argc;
	}
	int i;
	for(i=1;i<argc;++i){
		if(ftw(argv[i],display_info,20)==-1){
			perror("ftw()");
			exit(-1);
		}
	}
        return 0;
}
