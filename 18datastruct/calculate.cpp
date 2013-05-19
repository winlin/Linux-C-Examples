#include <iostream>
#include <stack>
using namespace std;

int main()
{
        string str="1+2*(3+4)/7+8*9";
        stack<int> result;
        stack<char> oper;
        for(int i=0;i<str.length();++i){
                char ch=str[i];
                if(isdigit(ch)){
                        result.push(ch);
                }
        }
        
                
        return 0;    
}
