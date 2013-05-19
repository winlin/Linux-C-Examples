#include <iostream>
using namespace std;
typedef int T;
//Ñ­»·¶ÓÁÐ
class Queue{
	T data[8];
	int size;
	int beg;
public:
	Queue():size(),beg(){}
	void push(const T& d){
		if(size>=8) throw "full";
		data[(beg+size++)%8] = d;
	}	
	void pop(){
		if(size<=0) throw "empty";
		beg++;
		size--;	
	}
	const T front(){return data[beg%8];}
	bool empty(){return size==0;}
	friend 
	ostream& operator<<(ostream&o,const Queue&q){
		for(int i=0; i<8; i++){
			o << q.data[i] << ' ';
		}
		return o;
	}
};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout << q << endl;	
	q.pop();
	q.pop();
	cout << q << endl;	
	q.push(7);
	q.push(8);
	cout << q << endl;	
	q.push(9);
	q.push(10);	
	cout << q << endl;	
	//q.push(11);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}

