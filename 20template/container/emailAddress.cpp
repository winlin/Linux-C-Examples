/*根据set无重复的特性，来新增邮件联系人*/
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

template<typename T>
void print(T beg,T end )
{
	while(beg!=end){
		cout<<*beg<<endl;
		++beg;
	}
}
int main()
{
	set<string> mails;
	ifstream fin("mail.lst");
	string str;
	while(!fin.eof()){
		fin>>str;
		mails.insert(str);
	}
	print(mails.begin(),mails.end());
	fin.close();
	ofstream fout("mail.lst");
	set<string>::iterator it=mails.begin();
	while(it!=mails.end()){
		str=*it;
		++it;
		fout<<str<<endl;;
	}
	fout.close();
	
        return 0;    
}
