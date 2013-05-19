#include <iostream>
#include <fstream>
using namespace std;

int main()
{
        ofstream fout("a.txt");
        fout<<100<<"abc "<<3.14<<endl;
        ifstream fin;
        fin.open("a.txt");
        int x;
        double d;
        string str;
        fin>>x>>str>>d;
        cout<<x<<" "<<d<<" "<<str<<endl;
        fin.close();
        fout.close();
        
        return 0;    
}
