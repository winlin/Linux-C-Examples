/*抛出的异常必须在函数的throw声明里全部包括，否则并不能被捕获
 *不用throw声明，表示可以抛出任何异常
 */
#include <iostream>
using namespace std;

void fa()throw(int,double,const char*,string)
{
        cout<<"1:int,2:double,3:str,4:other"<<endl;
        int x;
        cin>>x;
        if(x==1)
                throw 100;
        else if(x==2)
                throw 3.14;
        else if(x==3)
                throw "exception";
        else if(x==4) throw string("aadf");
        cout<<"fa() normally over"<<endl;
                        
}

int main()
{
        cout<<"main() starting..."<<endl;
        try{
                fa();
        }
        catch(int e){
                cout<<"Handling the INT type exception:"<<e<<endl;
        }
        catch(double e){
                cout<<"Handling the DOUBLE type exception:"<<e<<endl;
        }
        catch(const char* e){
                cout<<"Handling the CONST CHAR* type exception:"<<e<<endl;
        }
        catch(...){
                cout<<"Handling the other type exception"<<endl;
        }
        cout<<"The program continue run"<<endl;
        
        return 0;    
}
