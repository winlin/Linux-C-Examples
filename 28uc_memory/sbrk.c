/*扩展数据段的时候，如果内存允许，并且没有超过一个进程最大段的限制
 *如果一个内存页已经用完，那么会分配一个新的内存页。
 *分配单位是“一个内存页”。正因如此，有时候数据段越界了也没有出错。
 */
#include <stdio.h>
#include <unistd.h>
int main()
{
	int* p=sbrk(0);
	printf("current endpoint:%p\n",p);
	int* q=sbrk(sizeof(int));
	*q=123456789;
	printf("p=%p,q=%p\n",p,q);
	printf("%d\n",*p);
	double* r=sbrk(sizeof(double));
	*r=12.314;
	printf("r=%p,r=%f\n",r,*r);
	
        return 0;
}
