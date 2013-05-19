#include <iostream>
using namespace std;

void insertSort(int* a,int n)
{
	for(int i=1;i<n;++i){
		int x=a[i];
		int j;
		for(j=i; j>0&&a[j-1]>x ;j--)
			a[j]=a[j-1];
		a[j]=x;
	}
}

void insertSortB(int* a,int n)
{
	for(int i=1;i<n;++i){
		int x=a[i];
		int j;
		for(j=i;j>0&&a[j-1]<x;j--)
			a[j]=a[j-1];
		a[j]=x;
	}
}
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
	insertSort(a,10);
	print(a,10);
	insertSortB(a,10);
	print(a,10);
        return 0;    
}
