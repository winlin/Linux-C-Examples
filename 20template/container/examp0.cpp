/*标准容器的共性*/
/*iterator是一个内部类*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int>  v1;    //空参构造
	vector<int> v2=v1;  //拷贝构造
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	vector<int> v(a,a+10);   //区间构造，区间前闭后开
	vector<int>::iterator it=v.begin();
	for(;it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	v.erase(++v.begin());
        it=v.begin();
	for(;it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	v.erase(++v.begin());
	v.clear();
        return 0;    
}
