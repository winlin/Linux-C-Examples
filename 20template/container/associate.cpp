/*关联式容器底层使用的是二叉树*/
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int a[10]={1,2,3,45,6,7,7,89,9,10};
	multiset<int> mi(a,a+10);
	multiset<int>::iterator it=mi.begin();
	while(it!=mi.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	it=mi.find(6);
	if(it!=mi.end())
		cout<<"Find it:"<<*it<<endl;
	//*it=50; //不可以直接修改值
	mi.erase(it);    //按位置删除
	
	mi.insert(mi.begin(),50);  //关联式容器指定的位置参数无效
	 it=mi.begin();
	while(it!=mi.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	cout<<"8 appear times:"<<mi.count(8)<<endl;

	mi.erase(9);           //按值删除所有的特定值
	 it=mi.begin();
	while(it!=mi.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	mi.insert(7);    //直接插入元素
	 it=mi.begin();
	while(it!=mi.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	multiset<int>::iterator beg,end;
	beg=mi.lower_bound(7);    //开始位置
	end=mi.upper_bound(7);   //最后一个元素的下一个位置
	while(beg!=end){
		cout<<*beg<<" ";
		++beg;
	}
	cout<<endl;

	typedef  multiset<int>::iterator MII;
	pair<MII,MII> p=mi.equal_range(7);  //直接返回一个区间
	//p.first和p.second是两个public成员变量
	while(p.first!=p.second){
		cout<<*p.first<<" ";
		++p.first;
	}
	cout<<endl;
	
        return 0;    
}
