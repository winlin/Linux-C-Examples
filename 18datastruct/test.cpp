#include <iostream>
using namespace std;
typedef int T;
class Bst{
private:
        struct Node{
                T data;
                Node* left;
                Node* right;
                Node(const T& d):data(d),left(0),right(0){}
        };
        Node* root;
private:
        typedef Node* tree;
        void insert(Node* p,tree& t)
                {
                        if(t==NULL)
                                t=p;
                        else if(p->data>t->data)
                                insert(p,t->right);
                        else 
                                insert(p,t->left);  /*相等的时候，放到左子树*/
                }
        void tarvel(tree& t)
                {
                        if(t==NULL)
                                return ;
                        tarvel(t->left);
                        cout<<t->data<<" ";
                        tarvel(t->right);
                }
        
public:
        Bst():root(){}
        void insert(const T& d)
                {
                        Node* p=new Node(d);
                        insert(p,root);
                }
        void tarvel()
                {
                        tarvel(root);
                        cout<<endl;
                }
};

int main()
{
        Bst t;
        t.insert(3);
        t.insert(1);
        t.insert(6);
        t.insert(3);
        t.tarvel();
        
        return 0;    
}
