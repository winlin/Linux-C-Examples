#include <iostream>
#include <cstdio>
using namespace std;

void dbColorBall()
{
        long radBall[33]={0};
        long blueBall[16]={0};
        int ballAry[7]={0};
        
        cout<<"请输入要分析的数据项的个数"<<endl;
        long count;
        cin>>count;
        cout<<"请输入每一项中奖序列"<<endl;
        for(int i=0;i<count;++i){
                for(int j=0;j<7;++j){
                        cin>>ballAry[j];
                        if(j==6)
                                ++blueBall[ballAry[j]-1];
                        else
                                ++radBall[ballAry[j]-1];
                }
                
        }

        long long redSum=count*6;
        long long blueSum=count;
        double radRate[33]={0};
        double blueRate[16]={0};

        for(int i=0;i<33;++i){
                radRate[i]=100.0*radBall[i]/redSum;
        }
        for(int i=0;i<16;++i){
                blueRate[i]=100.0*blueBall[i]/blueSum;
        }

        cout<<"统计情况为："<<endl<<"求的总数为："<<redSum+blueSum
            <<"          "<<"红球共有："<<redSum<<"个       蓝球共有："
            <<blueSum<<"个"<<endl<<endl;
        cout<<"统计的红球的出现概率:"<<endl;
        for(int i=0;i<33;++i){
                printf("球%02d:%05.3lf%%    ",i+1,radRate[i]);
                if((i+1)%8==0)
                        cout<<endl;
        }
        cout<<endl;
        
        cout<<"统计的蓝球的出现概率:"<<endl;
        for(int i=0;i<16;++i){
                printf("球%02d:%05.3lf%%    ",i+1,blueRate[i]);
                if((i+1)%8==0)
                        cout<<endl;
        }
        cout<<endl;
       
}

int main()
{
        dbColorBall();
        return 0;    
}
