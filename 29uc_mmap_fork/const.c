#include <stdio.h>

int main()
{
	volatile const int a=10;
	int* p = (int*)&a;
	*p = 100;
	printf("a=%d\n", a);
}

