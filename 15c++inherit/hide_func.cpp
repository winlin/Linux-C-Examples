#include <iostream>
using namespace std;

class A {
public:
	void show(int a){cout<<"A::show(void) a="<<a<<endl;}
};

class B:public A{
public:
	void show(int a, int b){cout<<"B::show(void) a="<<a<<"  b="<<b<<endl;}
};

int main()
{
	A a;
	B b;
	a.show(11);
	b.A::show(12);
	b.show(11,12);
	
	return 0;
	
}
