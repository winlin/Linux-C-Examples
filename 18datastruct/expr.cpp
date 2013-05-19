#include <iostream>
using namespace std;
typedef char T;
class Stack{
	T data[100];
	int size;
public:
	Stack():size(){}	
	void push(const T& d){
		if(full()) throw "full";
		data[size++] = d;
	}
	void pop(){if(empty()) throw "empty";size--;}
	const T top(){return data[size-1];}
	bool empty(){return size==0;}
	bool full(){return size==100;}		 
};

//+ - * /  c1的优先级高于c2返回true,否则false
bool prior(char c1, char c2){
	return (c1=='*'||c1=='/')&&(c2=='+'||c2=='-');
}

int main(){
	string str = "1+2*(3+4)/7+8*9";
	cout << str << endl;
	Stack res;//结果栈	
	Stack exp;//运算符栈
	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		if(isdigit(ch)){//如果是数字，直接入结果栈
			res.push(ch);
		//如果是左括号,直接入运算符栈
		}else if(ch=='('){
			exp.push(ch);
		//如果是右括号，把运算符栈中的运算符放入结果栈，直到遇到左括号为止
		}else if(ch==')'){
			while(exp.top()!='('){
				res.push(exp.top());
				exp.pop();
			}
			exp.pop();
		}else{//否则，就是运算符，+ - * /
			while(!exp.empty()&&(exp.top()!='(')
				&&(!prior(ch,exp.top()))){
				res.push(exp.top());
				exp.pop();
			}
			exp.push(ch);
		}
	}
	while(!exp.empty()){
		res.push(exp.top());
		exp.pop();
	}
	Stack s;
	while(!res.empty()){
		s.push(res.top());
		res.pop();
	}
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}

