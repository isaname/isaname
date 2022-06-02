#include <iostream>
using namespace std;
int main()
{
    int** erwei;
    erwei=new int*[3];
    for(int i=0;i<3;i++){
        erwei[i]=new int[4];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            erwei[i][j]=j+i;
            cout<<erwei[i][j];
        }
    }
    
    return 0;
}