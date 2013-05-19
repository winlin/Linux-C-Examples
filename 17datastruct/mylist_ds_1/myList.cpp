#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;
typedef int T;
struct Node{
        T data;
        Node* next;
        Node(const T& d):data(d),next(){}
};
class List{
private:
        Node* head;
        Node* current;
        int sz;
private:
        Node*& getPtr(int pos);
public:
        List():head(),current(),sz(){}
        ~List();
        bool insert(const T& d);
        bool insert(const T& d,int pos);
        bool erase(int pos);
        void eraseValue(const T & d);
        bool setValue(const T& d,int pos);
        bool storeFile(const string& fileName);
        bool readFile(const string& fileName);
        T&   at(int pos);
        void display();
        void clear();
        int getSize(){return sz;}
};
Node*& List::getPtr(int pos)
{
        if(pos==0)return head;
        if(pos<0||pos>sz)
                throw out_of_range("out_of_index");
        Node* tmp=head;
        while(--pos)
                tmp=tmp->next;
        return tmp->next;
}
bool List::insert(const T& d)
{
        Node* p=new Node(d);
        if(!head){
                head=p;
                current=p;
        }
        else{
                current->next=p;
                current=p;
        }
        ++sz;
        return true;
}
bool List::insert(const T& d,int pos)
{
        if(pos<0||pos>sz)
                pos=sz;
        Node* pp=new Node(d);
        if(!head){
                head=pp;
                current=pp;
        }
        else{
                Node*& p=getPtr(pos);
                pp->next=p;
                p=pp;
                if(pos==sz)
                        current=pp;
        }
        ++sz;
        
        return true;
}
bool List::erase(int pos)
{
        if(pos<0||pos>=sz)
                return false;
        Node*& p=getPtr(pos);
        Node* tmp=p;
        p=p->next;
        delete tmp;
        --sz;
        if(pos==sz-1)
                current=getPtr(sz-2);
        
        return true;
}
void List::eraseValue(const T& d)
{
        Node* tmp=head;
        int pos=0;
        for(;pos<sz;++pos){
                if(tmp->data==d){
                        tmp=tmp->next;
                        erase(pos);

                        if(pos==sz-1){
                                current=getPtr(sz-2);
                        }
                        --pos;
                        
                }
                else
                        tmp=tmp->next;
        }
}
bool List::setValue(const T& d,int pos)
{
        if(pos<0||pos>=sz)
                return false;
        at(pos)=d;
        return true;
}
T& List::at(int pos)
{
        if(pos>=sz)
                throw out_of_range("out_of_index");
        Node* p=head;
        while(pos--){
                p=p->next;
        }
        return p->data;
}
bool List::storeFile(const string& fileName)
{
        ofstream outfile(fileName.c_str());
        if(!outfile.is_open()){
                cout<<"文件代开失败"<<endl;
                return false;
        }
        Node* p=head;
        for(int i=0;i<sz;++i){
                outfile<<(p->data)<<" ";
                p=p->next;
        }
        outfile.close();
        return true;
}
bool List::readFile(const string& fileName)
{
        ifstream infile(fileName.c_str());
        if(!infile.is_open()){
                cout<<"文件代开失败"<<endl;
                return false;
        }
        T num;
        while(!infile.eof()){
                infile>>num;
                insert(num);
        }
        infile.close();
        return true;
}

void List::display()
{
        Node* p=head;
        for(int i=0;i<sz;++i){
                cout<<p->data<<" ";
                p=p->next;
        }
        cout<<endl;
}
void List::clear()
{
        Node* tmp=NULL;
        while(head){
                tmp=head;
                head=head->next;
                delete tmp;
        }
        sz=0;
        head=current=0;
}

List::~List()
{
        clear();
}
        
int main()
{
        List intList;
        intList.insert(11,0);
        intList.insert(22,0);
        intList.display();
        
        for(int i=0;i<5;++i)
                intList.insert(i);
        cout<<intList.getSize()<<endl;
        intList.display();

        intList.setValue(33,3);
        intList.setValue(55,5);
        intList.setValue(11,0);
        intList.insert(44,4);
        intList.insert(66,6);
        intList.display();

        intList.erase(4);
        intList.display();
        intList.eraseValue(11);
        intList.eraseValue(66);
        intList.display();
        
        return 0;
}
