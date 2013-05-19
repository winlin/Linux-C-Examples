#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
        String str1("absdfsadc"),str2("esdfasdfaffg");
        cout<<"str1="<<str1<<endl
            <<"str2="<<str2<<endl;
        String str3=str1+str2;
        cout<<"str3="<<str3<<endl;
        if(str1<str2)
                cout<<"str1<str2"<<endl;
        else if(str1>str2)
                cout<<"str1>str2"<<endl;
        else
                cout<<"str1==str2"<<endl;
        cout<<"please input a string"<<endl;
        String str4;
        cin>>str4;
        cout<<"str4="<<str4<<endl;
        for(int i=0;i<str4.getLength();++i){
                cout<<str4[i];
        }
        cout<<endl;
        
        return 0;
}
