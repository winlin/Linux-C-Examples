#include <iostream>
#include "nDGrid.h"
using namespace std;

int main()
{
	NDGrid<int,3> my3DGrid;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int m=0;m<3;++m)
				my3DGrid[i][j][m]=(i+j+m);
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int m=0;m<3;++m){
				cout<<my3DGrid[i][j][m]<<"  ";
			}
		}
	}
	cout<<endl;
        return 0;    
}
