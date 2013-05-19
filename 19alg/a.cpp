#include <iostream>
using namespace std;
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
		if(a[l]==x)
			r--;
		else
			++l;
	}
	quickSort(a,l);
	quickSort(&a[l+1],n-l-1);
}
void print(int* a,int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[]={5,4,8,9,0,1,2,6,7,8};
	print(a,10);
	quickSort(a,10);
	print(a,10);
        return 0;    
}
