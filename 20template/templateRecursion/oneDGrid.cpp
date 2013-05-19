template<typename T>
const int NDGrid<T,1>::kDefaultSize;

template<typename T>
NDGrid<T,1>::NDGrid(int inSize):mSize(inSize)
{
	mElems=new T [mSize];
}

template<typename T>
NDGrid<T,1>::NDGrid(const NDGrid<T,1>& src)
{
	copyFrom(src);
}

template<typename T>
NDGrid<T,1>::~NDGrid()
{
	delete [] mElems;
}

template<typename T>
void NDGrid<T,1>::copyFrom(const NDGrid<T,1>& src)
{
	mSize=src.mSize;
	mElems=new T[mSize];
	for(int i=0;i<mSize;++i){
		mElems[i]=src.mElems[i];
	}
}

template<typename T>
NDGrid<T,1>& NDGrid<T,1>::operator=(const NDGrid<T,1>& rhs)
{
	if(this=&rhs)
		return (*this);
	delete [] mElems;
	copyFrom(rhs);
	return (*this);
}

template<typename T>
void NDGrid<T,1>::resize(int newSize)
{
	T* newElems=new T[newSize];
	for(int i=0;i<newSize&&i<mSize;++i){
		newElems[i]=mElems[i];
	}

	mSize=newSize;
	delete [] mElems;
	mElems=newElems;
}

template<typename T>
T& NDGrid<T,1>::operator[](int x)
{
	return (mElems[x]);
}

template<typename T>
const T& NDGrid<T,1>::operator[](int x) const
{
	return (mElems[x]);
}
