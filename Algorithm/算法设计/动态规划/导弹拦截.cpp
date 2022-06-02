#include <iostream>
#define MAX 100000
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }//初始化
    int temp[n][3];
    temp[0][0]=MAX;
    temp[0][1]=arr[0];
    temp[0][2]=1;
    for(int i=1;i<n;i++){
        if(temp[i-1][1]>arr[i]){
            //如果上一个拦截的高度大于当前高度
            temp[i][0]=temp[i-1][1];
            temp[i][1]=arr[i];
            temp[i][2]=temp[i-1][2]+1;//表明拦截数量
        }else{
            if(temp[i-1][0]>arr[i]){
                temp[i][0]=temp[i-1][0];
                temp[i][1]=arr[i];
                temp[i][2]=temp[i-1][2];
            }
            else{
                //彻底的拦截不了
                temp[i][0]=temp[i-1][0];
                temp[i][1]=temp[i-1][1];
                temp[i][2]=temp[i-1][2];
            }
        }
    }
    cout<<"最终拦截数量为:"<<temp[n-1][2]<<endl;


    return 0;
}