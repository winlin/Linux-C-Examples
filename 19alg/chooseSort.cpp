#include <iostream>
using namespace std;
void chooseSort(int* a,int n)
{
	int min;
	for(int i=0;i<n-1;++i){
		min=i;
		for(int j=i;j<n;++j){
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i){
			int tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
}

void chooseSortB(int* a,int n)
{
	int max;
	for(int i=n-1;i>0;--i){
		max=i;
		for(int j=i;j>=0;--j){
			if(a[j]<a[max])
				max=j;
		}
		if(max!=i)
			swap(a[i],a[max]);
	}
}

void print(int* a,int n)
{
	for(int i=0;i<n;++i){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}

int main()
{
	int a[]={13,14,15,16,11,13,28,18,19,20};
	print(a,10);
	chooseSort(a,10);
	print(a,10);
	chooseSortB(a,10);
	print(a,10);
        return 0;    
}
