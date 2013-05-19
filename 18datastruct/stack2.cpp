#include <iostream>
using namespace std;
#include "list/list.h"

class Stack{
	List list;
public:
	void push(const T& d){ list.push_front(d); }
	void pop(){list.erase(0);}
	const T top(){return list.front();}
	bool empty(){return list.size()==0;}
	bool full(){return false;}
};
class Stack2 : private List{
public:
	void push(const T& d){ push_front(d); }
	void pop(){erase(0);}
	const T top(){return front();}
	bool empty(){return size()==0;}
	bool full(){return false;}
};
int main()
{
	Stack2 s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}

