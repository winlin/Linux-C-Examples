#include <stdio.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc,char* argv[])
{
	char host[200];
	gethostname(host,sizeof(host));
	printf("%s\n",host);

	struct hostent* p=gethostbyname(host);
	if(!p){
		herror("gethostbyname");
		return -1;
	}
	printf("offical name:%s\n",p->h_name);
	printf("frist alias:%s\n",p->h_aliases[0]);
	
	char buf[200];
	inet_ntop(p->h_addrtype,p->h_addr_list[0],buf,sizeof(buf));
	printf("ip:%s\n",buf);
	return 0;
}
