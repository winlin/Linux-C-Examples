/*模板类的友元函数写在类的外部，
 *由于编译器只会检查类模板的语法是否正确，所以，要提前声明
 *友元函数，因为友元函数的参数包含类模板，所以也要先声明类模板;
 *在类的内部要使用模板参数 T 来实例化友元模板函数，这时参数可以直接写类模板的名字
 *因为编译器知道它是一个类模板,当然，写上也不会出错；
 *在类定义的后面，我们就可以按照定义模板函数的语法来定义即可，这时要把作为参数
 *的类模板写上"<T>",编译器是把 "Vector<T>"整个看成一个类型进行替换
 */
/*
export template<typename T> class Vector;
#include "tempFriend.h"
gcc 4.6.0还没有实现export关键字，所以，只能使用在头文件中包含.cpp文件的方法
*/
template<typename T>
void Vector<T>::insert(const T& t)
{
	data[size++]=t;
}
template<typename T>
istream& operator>>(istream& is,Vector<T>& v)
{
	is>>v.data[v.size++];
	return is;
}
template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& v)
{
	for(int i=0;i<v.size;++i){
		os<<v.data[i]<<" ";
	}
			return os;
}

