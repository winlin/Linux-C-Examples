#include <stdio.h>
#include <unistd.h>
#include "lib2.h"

int main(int argc,char* argv[])
{
	if(fork()==0){
		while(1){
			print1();
			sleep(1);
		}
	}
	if(fork()==0){
		while(1){
			print2();
			sleep(1);
		}
	}
	
	return 0;
}
