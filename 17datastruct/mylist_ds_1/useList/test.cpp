/*test.cpp*/
#include <iostream>
#include <cstdlib>
#include "myList.h"
using namespace std;

int main()
{
        cout<<"==========MENU=========="<<endl;
        cout<<"b.在链表的末尾插入数据"<<endl;
        cout<<"a.修改某一位置的数据"<<endl;
        cout<<"d.显示指定位置的元素"<<endl;
        cout<<"i.在指定位置插入数据"<<endl;
        cout<<"f.在链表的开始处添加元素"<<endl;
        cout<<"e.删除指定位置的数据"<<endl;
        cout<<"r.删除指定等于特定数据的所有数据"<<endl;
        cout<<"t.显示链表中的所有数据"<<endl;
        cout<<"c.清空链表中的数据"<<endl;
        cout<<"q.退出程序"<<endl;
        cout<<"s.把链表中的数据保存在指定文件"<<endl;
        cout<<"l.把指定文件中的全部数据添加到链表末尾"<<endl;
 
        char choose;
        int pos,num;
        string fileName;
        List oneList;
        while(1){
                cout<<"请输入选项>>"<<endl;
                cin>>choose;
                switch(choose){
                case 'b':
                        cout<<"请输入数据:"<<endl;
                        cin>>num;
                        oneList.insert(num);
                        break;
                case 'a':
                        cout<<"请输入位置和数据"<<endl;
                        cin>>pos>>num;
                        oneList.setValue(num,pos);
                        break;
                case 'd':
                        cout<<"请输入位置"<<endl;
                        cin>>pos;
                        cout<<oneList.at(pos)<<endl;
                        break;
                case 'i':
                        cout<<"请输入位置和数据"<<endl;
                        cin>>pos>>num;
                        oneList.insert(num,pos);
                        break;
                case 'f':
                        cout<<"请输入数据:"<<endl;
                        cin>>num;
                        oneList.insert(num,0);
                        break;
                case 'e':
                        cout<<"请输入位置:"<<endl;
                        cin>>pos;
                        oneList.erase(pos);
                        break;
                case 'r':
                        cout<<"请输入要删除的数据:"<<endl;
                        cin>>num;
                        oneList.eraseValue(num);
                        break;
                case 't':
                        cout<<"链表中数据为:"<<endl;
                        oneList.display();
                        break;
                case 'c':
                        cout<<"正在清空链表中的数据......"<<endl;
                        oneList.clear();
                        cout<<"清除完成."<<endl;
                        break;
                case 's':
                        cout<<"请输入文件名"<<endl;
                        cin>>fileName;
                        cout<<"正在保存数据到文件......"<<endl;
                        oneList.storeFile(fileName);
                        cout<<"数据已保存"<<endl;
                        break;
                case 'l':
                        cout<<"请输入文件名"<<endl;
                        cin>>fileName;
                        cout<<"正在读入数据...."<<endl;
                        oneList.readFile(fileName);
                        cout<<"数据已读入"<<endl;
                        break;
                case 'q':
                        cout<<"正在退出程序......"<<endl;
                        exit(0);
                        
                }
        }
        
        return 0;    
}
