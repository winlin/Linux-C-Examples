#include <iostream>
using namespace std;
class B;
class A{
private:
        int sum;
        //B* bObj;
        B& bObj;
public:
        A(B& bb,int sum=0):sum(sum),bObj(bb){}
        ~A(){}
};

class B{
private:
        int count;
public:
        B(int count=1):count(count){}
        int getCount(){return count;}
        void setCount(int m){count=m;}
};
int main()
{
        B bb(13);
        A aa(bb);
        return 0;
}
