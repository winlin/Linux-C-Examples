/*nDGrid.cpp*/
template<typename T,int N>
const int NDGrid<T,N>::kDefaultSize;

template<typename T,int N>
NDGrid<T,N>::NDGrid():mSize(kDefaultSize)
{
	mElems=new NDGrid<T,N-1>[mSize];
}

template<typename T,int N>
NDGrid<T,N>::NDGrid(int inSize):mSize(inSize)
{
	mElems=new NDGrid<T,N-1>[mSize];
	for(int i=0;i<mSize;++i){
		mElems[i].resize(inSize);
	}
}

template<typename T,int N>
NDGrid<T,N>::NDGrid(const NDGrid<T,N>& src)
{
	copyFrom(src);
}

template<typename T,int N>
NDGrid<T,N>::~NDGrid()
{
	delete [] mElems;
}

template<typename T,int N>
void NDGrid<T,N>::copyFrom(const NDGrid<T,N>& src)
{
	mSize=src.mSize;
	mElems=new NDGrid<T,N-1>[mSize];
	for(int i=0;i<mSize;++i){
		mElems[i]=src.mElems[i];
	}
}

template<typename T,int N>
NDGrid<T,N>& NDGrid<T,N>::operator=(const NDGrid<T,N>& rhs)
{
	if(this=&rhs)
		return *this;
	delete [] mElems;
	copyFrom(rhs);

	return (*this);
}

template<typename T,int N>
void NDGrid<T,N>::resize(int newSize)
{
	//allocate the new array with the new size
	NDGrid<T,N-1>* newElems=new NDGrid<T,N-1>[newSize];
	for(int i=0;i<newSize&&i<mSize;++i){
		newElems[i]=mElems[i];
		//resize the nested Grid elements recursively
		newElems[i].resize(newSize);
	}
	mSize=newSize;
	delete [] mElems;
	mElems=newElems;
}

template <typename T,int N>
NDGrid<T,N-1>& NDGrid<T,N>::operator[](int x)
{
	return (mElems[x]);
}

template <typename T,int N>
const NDGrid<T,N-1>& NDGrid<T,N>::operator[](int x) const
{
	return (mElems[x]);
}

