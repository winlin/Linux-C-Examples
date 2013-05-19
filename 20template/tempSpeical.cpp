/*特化的类，必须有对应的模板类才可以*/
/*进行模板匹配的时候，先找特里化类模板，不存在的话
 *在找偏特化类模板，最后再找类模板。注意顺序。
 */
#include <iostream>
#include <typeinfo>
using namespace std;
//模板类
template <typename T>
class Type{
public:
	static string name()
		{
			return typeid(T).name();
		}
};

class Person{
};

//特化类模板，必须要求模板Type存在
template<> class Type<int>{
public:
	static string name()
		{
			return "int" ;
		}
};
//偏特化类模板，偏特化对应一类类型特化
template<typename T>
class Type<T*>{
public:
	static string name()
		{
			return string("Point of")+typeid(T).name();
		}
};

template <typename T> string type(T d)
{
	return Type<T>::name();
}

int main()
{
	cout<<Type<Person>::name()<<endl;
	/*如果没有对int的特化类，下面的语句就会输出 ‘i’*/
	cout<<Type<int>::name()<<endl;
	type(300);
        return 0;    
}
