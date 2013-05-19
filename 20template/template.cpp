#include <iostream>
#include <typeinfo>
using namespace std;
/*T是类型参数，x是常规参数*/
/*常规参数由于编译器不允许，只能传int型的常量
 *C++规范，并没有规定，只是不同的编译器实现的问题
 * 一般和int类似的类型即可，如char
 */
template<typename T=int ,int x=20> class Buffer{
private:
	T data[x];
	int size;
public:
	Buffer():size(){}
	void insert(const T& d)
		{
			//模板中不能修改模板参数的值，模板参数是常量
			//x=2;
			data[size++]=d;
		}
};

int main()
{
	Buffer<int,100> b100;
	b100.insert(100);
	Buffer<int,20> b20;
	cout<<typeid(b100).name()<<endl;
	cout<<typeid(b20).name()<<endl;
	int a=100;
	//变量a不可作为模板的常规参数
	//Buffer<int ,a> b3;
	const int b=20;
	//模板的常规参数必须传递常量
	Buffer<int,b> b3;
	
	typedef unsigned int UINT;
	Buffer<UINT,10> b5;
	Buffer<unsigned int,10> b6;
	/*这两个类是同一种类型*/
	cout<<typeid(b5).name()<<endl;
	cout<<typeid(b6).name()<<endl;

	//即使有默认参数，也必须写上<>
	Buffer<> b7;
	
        return 0;    
}

