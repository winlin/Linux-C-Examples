#include <iostream>
using namespace std;
/*所有类型转换都可以使用C风格的强制类型转换*/
int main(  )
        {
                double d=3.14;
                //int x=( double )d;
                int x=static_cast<int>( d );

                char* str="abcdfe";
                //int* pi=( int* )str;
                int* pi=reinterpret_cast<int*>(str);

                const int ci=100;
                int* pci=( int* )&ci;
                *pci=200;   
                cout<<"ci="<<ci<<endl;  //此时打印100,因为编译器会作优化替换const

                int* pci2=const_cast<int*>( &ci );
                *pci2=300;
                cout<<"ci="<<*pci2<<endl; //此时打印300,因为会重新访问pci2指向的内存空间
                 
                return 0;
        }
