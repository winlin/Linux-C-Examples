#ifndef TEMPFRIEND_H
#define TEMPFRIEND_H

#include <iostream>
using namespace std;

template<typename T>class Vector;
template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& v);
template<typename T>
istream& operator>>(istream& is,Vector<T>& v);

template <typename T>
class Vector{
private:
	T* data;
	int length;
	int size;
public:
	Vector(int num):data(NULL),length(num),size(0)
		{
			data=new T[num];
		}
	~Vector(){delete [] data;}
	void insert(const T& t);
	friend ostream& operator<< <T> (ostream& os, const Vector& v);
	friend istream& operator>>  <T>(istream& is, Vector& v);
};

#include "tempFriend.cpp"
#endif
