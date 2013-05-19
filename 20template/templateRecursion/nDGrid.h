/*nDGrid.h*/
#ifndef NDGRID_H
#define NDGRID_H

template<typename T,int N>
class NDGrid{
private:
	void copyFrom(const NDGrid<T,N>& src);
	NDGrid<T,N-1>* mElems;                                   //pay your attention here
	int mSize;

public:
	NDGrid();
	NDGrid(int inSize);
	NDGrid(const NDGrid<T,N>& src);
	~NDGrid();

	NDGrid<T,N>& operator=(const NDGrid<T,N>& rhs);
	NDGrid<T,N-1>& operator[](int x);
	const NDGrid<T,N-1>& operator[](int x) const;
	void resize(int newSize);
	int getSize()const{return mSize;}
	static const int kDefaultSize=10;
	
};

template<typename T>
class NDGrid<T,1>{
protected:
	void copyFrom(const NDGrid<T,1>& src);
	T* mElems;                                                          //pay your attention here
	int mSize;
	
public:
	NDGrid(int inSize=kDefaultSize);
	NDGrid(const NDGrid<T,1>& src);
	~NDGrid();

	NDGrid<T,1>& operator=(const NDGrid<T,1>& rhs);
	T& operator[](int x);
	const T& operator[](int x) const;
	void resize(int newSize);
	static const int kDefaultSize=10;
	void getSize()const {return mSize;}
	
};

#include "nDGrid.cpp"
#include "oneDGrid.cpp"
#endif
