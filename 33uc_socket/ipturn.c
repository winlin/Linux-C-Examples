/*
 *inet_pton()同样也支持ipv6
 */
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc,char* argv[])
{
	const char* p="192.168.0.23";
	int addr;
	inet_pton(AF_INET,p,&addr);
	printf("%#x\n",addr);
	
	//内部格式转化成点分十进制
	char buf[13];
	inet_ntop(AF_INET,&addr,buf,sizeof(buf));
	printf("%s\n",buf);
		
	return 0;
}
