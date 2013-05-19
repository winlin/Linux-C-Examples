#include <iostream>
using namespace std;
/*for循环中尽量不要出现if语句*/
void sort(int* a ,int n)
{
	for(int i=0;i<n-1;++i){
		bool flag=true;
		for(int j=0;j<n-1-i;++j)
			if(a[j]>a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				flag=false;
			}
		if(flag)break;
	}
	
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
	sort(a,10);
	print(a,10);
        return 0;    
}
