/*模板类的成员函数和友元函数写在类的内部，可以不用
 *写成函数模板的形式
 */
#include <iostream>
using namespace std;
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
	void insert(const T& t)
		{
			data[size++]=t;
		}
	friend istream& operator>>(istream& is,Vector& v)
		{
			is>>v.data[v.size++];
			return is;
		}
	friend ostream& operator<<(ostream& os, const Vector& v)
		{
			for(int i=0;i<v.size;++i){
				os<<v.data[i]<<" ";
			}
			return os;
		}
};

int main()
{
	Vector<int> one(10);
	for(int i=0;i<10;++i)
		cin>>one;
	cout<<one<<endl;
	
        return 0;    
}
