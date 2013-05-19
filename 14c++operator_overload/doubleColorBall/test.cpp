#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dbColorBall()
{
        vector<long> redAry(33,0);
        vector<long> blueAry(16,0);
        vector<int> input(7,0);

        cout<<"请输入要分析的数据项的个数"<<endl;
        long count;
        cin>>count;
        cout<<"请输入每一项中奖序列"<<endl;
        for(int i=0;i<count;++i){
                for(int j=0;j<7;++j){
                        cin>>input[j];
                        if(j==6)
                                blueAry[input[j]-1]+=1;
                        else
                                redAry[input[j]-1]+=1;
                }
                
        }
        long long redSum=count*6;
        long long blueSum=count;
        vector<float> redRate(33,0.0);
        vector<float> blueRate(16,0.0);

        for(int i=0;i<33;++i){
                redRate[i]=100.0*redAry[i]/redSum;
        }
        for(int i=0;i<16;++i){
                blueRate[i]=100.0*blueAry[i]/blueSum;
        }

        cout<<"统计情况为："<<endl<<"求的总数为："<<redSum+blueSum
            <<"          "<<"红球共有："<<redSum<<"个       蓝球共有："
            <<blueSum<<"个"<<endl<<endl;
        

}
int main()
{

        return 0;    
}
