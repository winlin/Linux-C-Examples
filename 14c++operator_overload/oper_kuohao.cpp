/*
  类型转换函数
  构造函数也是具有类型转换的功能
  这两种方法都可以，但是注意实现的地方不同
  声明显示转换explicit
*/
#include <iostream>
using namespace std;
class Integer;
class F{
        int n;
        int d;
public:
        F(int n,int d):n(n),d(d){}
        friend ostream& operator<<(ostream& os,F& f)
                {
                        return os<<f.n<<"/"<<f.d;
                }
       explicit operator double() /*类型转换函数，不允许写返回值，默认就是double*/
        {
                return 1.0*n/d;
        }
        explicit operator int()
        {
                return n/d;
        }
        operator Integer()   /*冲突*/
        {
                cout<<"F::operator Integer() called"<endl;
                return n/d;
        }
        
};

class Integer{
        int x;
public:
        Integer(int x):x(x){}
        Integer(F ff)    /*冲突*/
        {
                cout<<"Integer construction"<<endl;
                x=(int)ff;
        }
        friend ostream& operator<<(ostream& os,Integer& i)
                {
                        return os<<i.x;
                }
        
};

void fa(int x){}
void fb(double d){}
void fc(Integer ii){}

int main()
        {
                F f1(9,2);
                cout<<f1<<endl;
                double d1=(double)f1;  /*C++里面的强制类型转换也是一种运算符*/
                cout<<d1<<endl;
                int ii=(int)f1;        /*如果没有explicit可以不用写强制类型转换(int)，它会自动
                                         寻找自动转换，称之为自动转换*/
                cout<<ii<<endl;

                fa(f1);               /*函数参数可以自动类型转换*/
                fb(f1);
                Integer one=f1;       /*冲突*/
                cout<<one<<endl;
                
                int x=100;
                fc(x);               /*会调用Integer的构造函数进行转换*/

                fc(f1);              /*冲突*/
                return 0;
        }
/*
  对于“冲突”的地方，我们应该只选择一种方式，要么实现构造函数，要么实现类型转换；
  建议实现类型转换
 */
