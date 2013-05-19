#include <iostream>
using namespace std;
typedef int T;
class Stack{
	T data[100];
	int size;
public:
	Stack():size(){}	
	//入栈
	void push(const T& d){
		if(full()) throw "full";
		data[size++] = d;
	}
	//出栈
	void pop(){if(empty()) throw "empty";size--;}
	//查看栈顶元素
	const T top(){return data[size-1];}
	//栈是否为空
	bool empty(){return size==0;}
	//栈是否满
	bool full(){return size==100;}		 
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}	
	cout << endl;
}

