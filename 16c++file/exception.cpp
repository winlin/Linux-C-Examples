#include <iostream>
using namespace std;
void service()throw(int)
{
        int x=0;
        cin>>x;
        if(x%2==0)
                throw 1;
        
}

int main()
{
        try{
                service();    
        }
        catch(int e){
                cout<<"处理int型异常"<<e<<endl;
        }
        
        return 0;    
}
