#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int* a,int n)
{
	if(n<1)     /*分组的长度有可能为0*/
		return;
	int l=0;
	int r=n-1;
	int m=a[l];
	while(l<r){
		while(l<r && m<=a[r]) r--;
		a[l]=a[r];
		while(l<r && a[l]<=m) l++;
		a[r]=a[l];
	}
	a[l]=m;
	quickSort(a,l);
	quickSort(a+l+1,n-l-1);
}

void quickSortB(int* a,int n)
{
	if(n<1)
		return;
	int l=0;
	int r=n-1;
	int m=a[l];
	while(l<r){
		while(l<r && m>=a[r])--r;
		a[l]=a[r];
		while(l<r && m<=a[l])++l;
		a[r]=a[l];
	}
	a[l]=m;
	quickSortB(a,l);
	quickSortB(a+l+1,n-l-1);
}

/*
  void quickSort(int* a,int n)
{
	if(n<1)
		return;
	int l=0;
	int r=n-1;
	int x=a[l];
	while(l<r){
		if(a[l]>a[r])
			swap(a[l],a[r]);
		if(a[l]==x)   //说明没有移动，即a[r]>a[l],这时r--，也就是右边下一个元素
			r--;
		else           //否则的话a[r]<a[l],即x移到了右边，这时l++判断左边下一个元素
			++l;  
	}
	quickSort(a,l);
	quickSort(&a[l+1],n-l-1);
}
 */
/*原始的快速排序算法，上面的是经过优化的
  void quickSort(int* a,int n)
{
	if(n<1)     分组的长度有可能为0
		return;
	int l=0;
	int r=n-1;
	while(l<r){
		while(l<r && a[l]<=a[r]) r--;
		swap(a[l],a[r]);
		while(l<r && a[l]<=a[r]) l++;
		swap(a[l],a[r]);
	}
	quickSort(a,l);
	quickSort(a+l+1,n-l-1);
}
  */
void print(int* a,int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int main()
{
	int a[]={13,14,15,16,11,13,28,18,19,20};
	print(a,10);
	quickSort(a,10);
	print(a,10);
	quickSortB(a,10);
	print(a,10);
        return 0;    
}
