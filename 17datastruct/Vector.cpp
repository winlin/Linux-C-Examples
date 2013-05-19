#include <iostream>
using namespace std;
typedef int T;
class Vector{
private:
        T* data;
        int size;
        int max;
private:
        void expend()
                {
                        max=2*(max==0?1:max);
                        T* tmp=new T[max];
                        for(int i=0;i<size;++i)
                                tmp[i]=data[i];
                        delete [] data;
                        data=tmp;
                }
public:
        Vector(const Vector& v)
        {
                size=v.size;
                max=v.max;
                data=new T[max];
                for(int i=0;i<size;++i)
                        data[i]=v.data[i];
        }
        explicit Vector(int len=0):size(0),max(len)
        {
                data=new T[len];
        }
        ~Vector(){delete [] data;}


        Vector& operator=(const Vector& v)
        {
                if(this==&v)
                        return *this;
                delete [] data;
                data=new T[v.max];
                for(int i=0;i<v.size;++i)
                        data[i]=v.data[i];
                size=v.size;
                max=v.max;
        }
        void insert(const T& d)
                {
                        insert(d,size);
                }
        void insert(const T& d,int pos)
                {
                        if(pos<0||pos>size)
                                pos=size;     /*越界放在最后一个位置*/
                        if(size==max)
                                expend();
                        for(int i=size;i>pos;--i)
                                data[i]=data[i-1];
                        data[pos]=d;
                        ++size;
                }
        bool erase(int pos)
                {
                        if(pos<0||pos>=size)
                                return false;
                        for(int i=pos;i<size-1;++i)
                                data[i]=data[i+1];
                        --size;
                        return true;
                }
        bool setValue(const T& d,int pos)
                {
                        if(pos<0||pos>=size)
                                return false;
                        data[pos]=d;
                        return true;
                }
        T& at(int pos)
        {
                if(pos<0||pos>size)
                        throw "out_of_index";
                return data[pos];
        }
        const int getSize()
                {
                        return size;
                }
        T& operator[](int pos)
        {
                return data[pos];
        }
        friend ostream& operator<<(ostream& os,const Vector& v)
                {
                        for(int i=0;i<v.size;++i)
                                os<<v.data[i]<<" ";
                        return os;
                }
};

int main()
{
        Vector v(10);
        for(int i=0;i<10;++i)
                v.insert(i+1);
        v.insert(100,3);
        v.insert(200,0);
        
        cout<<v<<endl;

        Vector v1=v;
        cout<<v1<<endl;
        Vector v2(v);
        cout<<v2<<endl;
        v2.erase(3);
        cout<<v2<<endl;
        v2.setValue(400,4);
        cout<<v2<<endl;

        for(int i=0;i<v2.getSize();++i)
                cout<<v2.at(i)<<" ";
        cout<<endl;
        for(int i=0;i<v2.getSize();++i)
                cout<<v2[i]<<" ";
        return 0;    
}
