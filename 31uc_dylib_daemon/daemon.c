/*
 *create a daemon process
 *子进程会继承父进程的消息处理函数
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int termNum=0;
void term(int sig)
{
	termNum=1;
}

int main()
{
	//fork parent process end
	if(fork()!=0) return 0;
	signal(SIGTERM,term);
	
	printf("cid=%d\n",getpid());
	
	int i;
	//close the file descriptor
	for(i=0;i<256;++i){
		close(i);
	}

	//build self group id
	//creates a session and sets the process group ID
	setsid();

	//chang the privilage  mask
	umask(0000);

	//set the current directory
	chdir(getpwuid(getuid())->pw_dir);

	//do the work you want
	char c='A';
	int fd;
	while(!termNum){
		fd=open("abc",O_WRONLY|O_CREAT|O_APPEND,0644);
		if(fd<0){
			perror("open");
			continue;
		}
		write(fd,&c,1);
		close(fd);
		if(++c>'Z')
			c='A';
		sleep(1);
	}
	
	return 0;
}
