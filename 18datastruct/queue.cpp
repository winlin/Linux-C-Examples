#include <iostream>
#include "list/list.h"
using namespace std;
class Queue : private List{
public:
	void push(const T& d){push_back(d);}
	void pop(){erase(0);}
	const T front(){return List::front();}
	bool empty(){return size()==0;}
};
int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}

