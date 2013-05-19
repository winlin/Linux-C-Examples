#include <iostream>
using namespace std;
int search_line(char* cs,int n,char c)
{
        for(int i=0;i<n;++i)
                if(cs[i]==c)
                        return i;
        return -1;
}
int search_binary(char* cs,int n,char c)
{
        int L=0;
        int R=n-1;
        int M;
        while(L<=R){  /*L=R保证开始和结束时都成功*/
                M=(L+R)/2;
                if(cs[M]==c)
                        return M;
                else if(cs[M]<c)
                        L=M+1;
                else
                        R=M-1;
        }
        return -1;
}
/***递归****/
int search_binary_rr(char* cs,int start,int end,char c)
{
        int m=(start+end)/2;
        if(start>end)
                return -1;
        else if(cs[m]==c)
                return m;
        else if(cs[m]<c)
                return search_binary_rr(cs,m+1,end,c);
        else
                return search_binary_rr(cs,start,m-1,c);
}
int search_binary_r(char* cs,int n,char c)
{
        if(cs[n/2]==c)
                return n/2;
        else
                search_binary_rr(cs,0,n-1,c);
}
/**********/

int main()
{
        char cs[]={'A','B','C','D','E','F','G','H'};
        int i=search_binary(cs,7,'E');
        cout<<i<<endl;
        cout<<search_binary(cs,8,'A')<<endl;
        cout<<search_binary(cs,8,'H')<<endl;
        cout<<search_binary(cs,8,'O')<<endl;
        cout<<search_binary_r(cs,8,'E')<<endl;
        
        return 0;    
}
