#include <iostream>
#include <list>
using namespace std;
typedef int T;
class Queue{
private:
        T data[8];
        short int begin;
        int size;
public:
        Queue():begin(0),size(0){}
        void push(const T& d)
                {
                        if(size>=8)
                                throw "full";
                        data[(begin+size++)%8]=d;
                }
        void pop()
                {
                        if(size<=0)
                                throw "empty";
                        begin=(begin+1)%8;   /*++begin;长时间运行会导致溢出*/
                        --size;
                }
        const T top()
                {
                        return data[begin%8];
                }
        bool empty()
                {
                        return size==0;
                }
        
};

int main()
{
        Queue q;
        int m=0;
        while(1){
                for(int i=0;i<8;++i)
                        q.push(i);
                for(int i=0;i<8;++i)
                        q.pop();
                cout<<m++<<" ";
                
        }
        return 0;    
}

