#include <iostream>
using namespace std;
typedef int T;
struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d):data(d), left(0), right(0){}
};

class Bst {
private:

        Node* root;
        int sz;
private:
        typedef Node* tree;
        void insert(Node* p, tree& t)
                {
                        if (t == NULL)
                                t = p;
                        else if (p->data > t->data)
				insert(p,t->right);
                        else   /*值可以重复，默认往左子树插入*/
                                insert(p,t->left);
                }
        void tarvel(tree& t)
                {
                        if (t == NULL)
                                return ;
                        tarvel(t->left);
                        cout<< t->data << " ";
                        tarvel(t->right);
                }
        void clear(tree& t)
                {
                        if(t==NULL)
                                return;
                        clear(t->left);
                        clear(t->right);
                        delete t;
                }
        tree& find(const T& d,tree& t)
                {
                        if(t==NULL)
                                return t;
                        if(t->data==d)
                                return t;
                        if(t->data > d)
                                return find(d,t->left);
                        else
                                return find(d,t->right);
                }
        /*int getDepth(tree& t)
                {
                        if(t==NULL)
                                return 0;
                        if(getDepth(t->right) > getDepth(t->left))
                                return (getDepth(t->right)+1);
                        else
                                return (getDepth(t->left)+1);
                        
                }*/
        int getDepth(tree& t)
                {
                        if(t==NULL)return 0;
                        int l=getDepth(t->left);
                        int r=getDepth(t->right);
                        return l>r?l+1:r+1;
                }
        void print(tree& t,char c,int d)
                {
                        if(t==NULL){
                                if(t==root)
                                        cout<<"树为空"<<endl;
                                return ;       
                        }
                        print(t->left,'/',d+1);
                        for(int i=0;i<d;++i)
                                cout<<' ';
                        cout<<c<<t->data<<endl;
                        print(t->right,'\\',d+1);
                }
public:
        Bst():root(),sz(){}
        ~Bst(){clear();}
        void insert(const T& d)
                {
                        Node* p=new Node(d);
                        insert(p,root);
                        ++sz;
                }
        void tarvel()
                {
                        tarvel(root);
                        cout<<endl;
                }
        void clear()
                {
                        clear(root);
                        sz=0;
                        root=NULL;
                }
        Node*& find(const T& d)
                {
                        return find(d,root);
                }
        bool remove(const T& d)
                {
                        tree& t=find(d);
                        if(t==NULL)
                                return false;
                        /*将左子树插入到右子树*/
                        insert(t->left,t->right);
                        /*右子树向上提一级*/
                        Node* p=t;
                        t=t->right;
                        delete p;
                        --sz;
                        return true;
                }
        void removeAll(const T& d)
                {
                        while(remove(d));
                }
        void modify(const T& old,const T& newVal)
                {
                        while(remove(old))
                                insert(newVal);
                }
        void getDepth()
                {
                        cout<<"d:"<<getDepth(root)<<endl;
                }
        void print()
                {
                        int d=0;
                        print(root,'*',d);
                }
        int getSize()
                {
                        return sz;
                }
};

int main()
{
        Bst t;
        t.getDepth();
        t.insert(5);
        t.insert(8);
        t.insert(7);
        t.insert(9);
        t.insert(3);
        t.insert(2);
        t.insert(4);
        t.tarvel();
        t.getDepth();
        t.print();
        
        t.remove(5);
        t.tarvel();
        t.getDepth();
        t.print();

        t.remove(7);
        t.tarvel();
        cout<<t.getSize()<<endl;
        t.getDepth();
        t.clear();
        cout<<t.getSize()<<endl;
        t.print();
        return 0;    
}


