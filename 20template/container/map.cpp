/*map里面的 KEY 也会自动排序*/
#include <iostream>
#include <map>
using namespace std;

template<typename T>
void print(T beg,T end)
{
	while(beg!=end){
		cout<<*beg<<endl;
		++beg;
	}
}
//map.insert()的参数是一个pair对象,有4种方式
int main()
{
	map<string,string> m;
	m.insert(map<string,string>::value_type("name","winlin"));
	m.insert(pair<string,string>("age","30"));
	m.insert(make_pair("gender","male"));
	m["high"]="173.5";   //m.insert(make_pair("high","173.5"));
	m["name"]="liuguangtao";   //修改name KEY对应的值
	cout<<"name:"<<m["name"]<<endl;
	cout<<endl;
	
	//map的 *iterator返回的是一个pair对象，不可直接输出
	map<string,string>::iterator beg=m.begin();
	while(beg!=m.end()){
		pair<string,string> v=*beg;
		cout<<v.first<<" : "<<v.second<<endl;
		//也可以直接使用迭代器访问
		cout<<beg->first<<" : "<<beg->second<<endl;
		++beg;

	}
	return 0;    
}
