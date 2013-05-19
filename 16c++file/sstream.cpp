#include <iostream>
#include <sstream>
using namespace std;

int main()
{
        string str="13 3.14 abdcef";
        istringstream iss(str);
        int x;
        double y;
        string str2;
        iss>>x>>y>>str2;
        cout<<x<<y<<str2<<endl;
        return 0;    
}
