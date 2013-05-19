#include <stdio.h>
#include <arpa/inet.h>

void showbytes(void* p,int bytes)
{
	typedef unsigned char UC;
	UC* b=p;
	while(bytes--){
		printf("%02x ",*b++);
	}
	printf("\n");
}

int main(int argc,char* argv[])
{
	short s=0x1234;
	long n=0x56789;
	showbytes(&s,2);
	showbytes(&n,4);
	s=htons(s);
	n=htonl(n);
	printf("---------------\n");
	showbytes(&s,2);
	showbytes(&n,4);
	printf("---------------\n");
	printf("%0x\n",s);
	printf("%0x\n",n);
	printf("---------------\n");
	s=ntohs(s);
	n=ntohl(n);
	printf("%0x\n",s);
	printf("%0x\n",n);
	return 0;
}
