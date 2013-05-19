/*
 *ios::in ios::out ios::trunc
 *ios::app
 *注意，fstream要操作的文件，必须存在
 *     ofstream会创建一个新的文件
 */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
        fstream fs("b.txt",ios::in|ios::out);
        if(!fs.is_open())
                cout<<"file open fialed"<<endl;
        
        fs.put('A');
        fs.put('B');
        fs.put('C');
        fs.close();
        
        return 0;    
}
