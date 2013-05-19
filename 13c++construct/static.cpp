#include <iostream>
using namespace std;
/*静态成员变量属于整个类，和具体的对象无关，分配的空间也就和对象无关
  它需要单独分配空间
  静态成员函数同样也是属于整个类，可以通过对象调用，也可以通过classname::functionName()
  来调用.
  静态成员函数不可以访问非static数据成员！在静态成员函数中没有this指针。
*/
class Example{
public:
  int x;
  static int s;
  static void  show();
};
int Example::s;   //分配静态成员的空间

void Example::show(  ){
  cout<<s<<"  "<<endl;
}

int main(){
  Example e,e1;
  e.x=10;
  e.s=20;
  cout<<e.s<<endl;
  e1.x=100;
  e1.s=200;
  cout<<e1.s<<endl;
  cout<<e.s<<endl;
  e1.show(  );
  return 0;
}
