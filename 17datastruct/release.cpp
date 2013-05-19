#include <iostream>
using namespace std;
typedef int T;
template <typename T>
class List{
private:
        struct Node{
                T data;
                Node* next;
                Node(const T& d):data(d),next(){}
        };
        Node* head;
        int sz;
private:
        Node*& getPtr(int pos);
public:
        List():head(),sz(){}
        ~List();
        bool insert(const T& d);
        bool insert(const T& d,int pos);
        bool erase(int pos);
        bool erase(const T & d);
        bool setValue(const T& d,int pos);
        T&   at(int pos);
        void display();
        int getSize(){return sz;}
};
struct Node;
template <typename T>
Node*& List<T>::getPtr(int pos)
{
        if(pos==0)return head;
        if(pos<0||pos>sz)
                throw out_of_range("out_of_index");
        Node* tmp=head;
        while(--pos)
                tmp=tmp->next;
        return tmp->next;
}

template<typename T>
bool List<T>::insert(const T& d)
{
        Node* p=new Node(d);
        Node* tmp=head;
        if(!head){
                head=p;
                tmp=p;
        }
        else{
                tmp->next=p;
                tmp=p;
        }
        ++sz;
        return true;
}

template<typename T>
bool List<T>::insert(const T& d,int pos)
{
        if(pos<0||pos>sz)
                pos=sz;
        Node*& p=getPtr(pos);
        Node* pp=new Node(d);
        pp->next=p;
        p=pp;
        ++sz;
        return true;
}

template<typename T>
bool List<T>::erase(int pos)
{
        if(pos<0||ps>=sz)
                return false;
        Node*& p=getPtr(pos);
        Node* tmp=p;
        p=p->next;
        delete tmp;
        --sz;
        return true;
}

template<typename T>
void List<T>::erase(const T& d)
{
        Node* tmp=head;
        while(tmp){
                if((tmp==head)&&(tmp->data==d->data)){
                        erase(0);
                        continue;
                }
                else if(tmp->next->data==d.data){
                        Node* t=tmp->next;
                        tmp->next=t->next;
                        delete t;
                        continue;
                }
                tmp=tmp->next;
        }
        --sz;
}

template<typename T>
bool List<T>::setValue(const T& d,int pos)
{
        if(pos<0||pos>=sz)
                return false;
        Node*& p=getPtr(pos);
        p->data=d;
        return true;
}

template<typename T>
T& List<T>::at(int pos)
{
        if(pos>=sz)
                throw out_of_range("out_of_index");
        Node* p=head;
        while(pos--){
                p=p->next;
        }
        return p->data;
}

template<typename T>
void List<T>::display()
{
        Node* p=head;
        for(int i=0;i<sz;++i){
                cout<<tmp->data<<" ";
                tmp=tmp->next;
        }
        cout<<endl;
}

template<typename T>
List::~List()
{
        Node* tmp=NULL;
        while(head){
                tmp=head;
                head=head->next;
                delete tmp;
        }
}
        
int main()
{
        List<int> intList;
        for(int i=0;i<5;++i)
                intList.insert(i);
        cout<<intList.getSize()<<endl;
        intList.display();
        return 0;
}
