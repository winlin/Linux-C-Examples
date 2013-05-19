#include <iostream>
#include <map>
using namespace std;

class Student{
private:
	string name;
	int age;
public:
	Student(string name,int age):name(name),age(age){}
	friend ostream& operator<<(ostream& os,const Student& s)
		{
			return os<<s.name<<" "<<s.age;
		}
	friend bool operator<(const Student& one,const Student& two)
		{
			return one.name<two.name;
		}
};

int main()
{
	map<Student,int> msi;
	Student s1("aaa",20);
	Student s2("bbb",23);
	Student s3("ccc",22);
	Student s4("ddd",25);

	msi.insert(make_pair(s1,98));
	msi.insert(make_pair(s2,96));
	msi.insert(make_pair(s3,98));
	msi.insert(make_pair(s4,60));
	map<Student,int>::iterator it=msi.begin();
	while(it!=msi.end()){
		cout<<it->first<<"  "<<it->second<<endl;
		++it;
	}

        return 0;    
}
