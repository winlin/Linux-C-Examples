/*set容器只存放不同的值*/
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
void print(T beg,T end )
{
	while(beg!=end){
		cout<<*beg<<" ";
		++beg;
	}
	cout<<endl;
}

int main()
{
	srand(time(NULL));
	set<int> si;            //set是不会存放重复数据的
	for(int i=0;i<10000;++i){
		si.insert(rand()%20);
	}
        print(si.begin(),si.end());
	
        return 0;    
}
