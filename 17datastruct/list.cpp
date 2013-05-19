#include <iostream>
#include <stdexcept>
using namespace std;
typedef int T;
class List{
        struct Node{
                T data;
                Node* next;
                Node(const T& d):data(d),next(){}
        };
        Node* head;
        int sz;
private:
        Node*& getPos(int pos)
        {
                /*返回的指针是pos位置上一个Node节点的next指针*/       
                if(pos<0||pos>sz)
                        pos=sz;          /*超过范围插入到末尾*/
                else if(pos==0)
                        return head;
                
                Node* tmp=head;
                while(--pos)
                        tmp=tmp->next;
                return tmp->next;
        }
public:
        List():head(),sz(){}
        void insert(const T& d)
                {
                        Node* tmp=new Node(d);
                        tmp->next=head;              /*倒序插入*/
                        head=tmp;
                        ++sz;
                }
        void insert(const T& d,int pos)
                {
                        Node*& tmp=getPos(pos);
                        Node* p=new Node(d);
                        p->next=tmp;
                        tmp=p;
                        ++sz;
                }
        bool erase(int pos)
                {
                        if(pos<0||pos>=sz)
                                return false;
                        Node*& tmp=getPos(pos);
                        Node* p=tmp;
                        tmp=tmp->next;
                        delete p;
                        --sz;
                        return true;
                }
        bool setValue(const T& d,int pos)
                {
                        if(pos<0||pos>=sz)
                                return false;
                        Node*& p=getPos(pos);
                        p->data=d;
                        return true;
                }
        void dispaly()
                {
                        Node* p=head;               /*不可修改头指针*/
                        while(p){
                                cout<<p->data<<" ";
                                p=p->next;
                        }
                        cout<<endl;
                }
        int size()
                {
                        return sz;
                }
        T& at(int pos)
        {
                if(pos<0||pos>=sz)
                        throw out_of_range("out_of_index");
                Node*& p=getPos(pos);
                return p->data;
        }
        ~List()
        {
                while(head){
                        Node* tmp=head;
                        head=head->next;
                        delete tmp;
                }
        }
        
};


int main()
{
        List one;
        for(int i=0;i<5;++i)
                one.insert(i+1);
        one.dispaly();
        one.insert(20,0);
        one.dispaly();
        one.insert(50,30);
        one.insert(222,2);
        one.dispaly();

        one.erase(0);
        one.dispaly();
        one.erase(3);
        one.dispaly();

        one.setValue(1,1);
        one.setValue(0,0);
        one.setValue(555,5);
        one.setValue(666,6);
        one.dispaly();
        cout<<one.size()<<endl;
        for(int i=0;i<one.size();++i)
                cout<<one.at(i)<<" ";
        cout<<endl;
        
        return 0;    
}
