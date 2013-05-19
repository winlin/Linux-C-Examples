#include <iostream>
using namespace std;

class A{
public:
	A(){cout<<"A()"<<endl;}
	~A(){cout<<"~A()"<<endl;}
};
class B{
public:
	B(){cout<<"B()"<<endl;}
	~B(){cout<<"~B()"<<endl;}
};
A obja;
int main()
{
	B objb;
	exit(0);//_exit(0);
	return 0;
}

