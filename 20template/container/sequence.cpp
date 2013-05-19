/*序列容器 */
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> la(5);
	
	list<int>::iterator it=la.begin();
	while(it!=la.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	la.insert(la.end(),3,300);
	it=la.begin();
	while(it!=la.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	int a[5]={22,33,44,55,66};
	la.insert(la.end(),a,a+5);
	it=la.begin();
	while(it!=la.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	
        return 0;    
}
