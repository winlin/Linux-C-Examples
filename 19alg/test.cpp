#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int CNT=1000000;
 void quickSort(int* a,int n)
{
	if(n<1)
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
void print(int *a ,int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int main()
{
	int a[CNT];
	srand(time(NULL));
	for(int i=0;i<CNT;++i)
		a[i]=rand()%CNT;
	cout<<"Befor"<<endl;
	print(a,20);
	clock_t start=clock();
	quickSort(a,CNT);
	clock_t end=clock();
	cout<<"After"<<endl;
	print(a,10);
	long t=end-start;
	cout<<"Use time seconds:"<<1.0*t/CLOCKS_PER_SEC<<endl;
        return 0;    
}
