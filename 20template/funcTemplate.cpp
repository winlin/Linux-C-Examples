/*函数模板*/
#include <iostream>
using namespace std;
/*注意函数模板的格式*/
template <typename T>
void fa(T x)
{
	cout<<x<<endl;
}

template<typename C,typename D>
C implicit_cast(D u)
{
	return u;
}
void g(int i)
{
	implicit_cast(i);    //Error,无法推断出参数类型
	implicit_cast<double>(i);  //C为double，D为int
	implicit_cast<char,int>(i);  //C为char，D为int
	implicit_cast<char*,int>(i);  //Error int不可转为char*
}
/*注意，不同的模板参数类型转换常常需要注意细节过程*/

int main()
{
	fa<int>(100);
	fa<double>(53.343);
	//函数模板具有类型判断功能
	fa(100);
	fa("abc");
        return 0;    
}
