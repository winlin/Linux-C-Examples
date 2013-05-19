#ifndef LIST_H
#define LIST_H
typedef int T;
class List{
	struct Node{//ÄÚ²¿Àà
		T data;
		Node* next;
		Node(const T& d):data(d),next(){}
	};	
	Node* head;
	int sz;
	Node*& getptr(int pos);
public:
	List():head(),sz(){}
	~List(){clear();}
	List& insert(const T& d, int pos=0);
	bool erase(int pos);
	void remove(const T& d);
	bool set(const T& d, int pos);
	T& at(int pos);
	void travel();
	void clear();
	int size(){ return sz;}
	void push_back(const T& d){insert(d, sz);}
	void push_front(const T& d){insert(d);}
	const T front(){return head->data;}
	const T back(){ return getptr(sz-1)->data; }
};
#endif

