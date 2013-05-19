#include <stdio.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

void func(int sig)
{
	struct winsize s;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &s);
	printf("\r´°¿Ú³ß´ç%d x %d     ",s.ws_row,s.ws_col);
	fflush(stdout);
}
int main()
{
	signal(SIGWINCH, func);
	while(1);
}

