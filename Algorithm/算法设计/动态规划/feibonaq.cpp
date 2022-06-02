#include <iostream>
#include<string.h>
#define N 10
using namespace std;
int * arr=new int[N];
int feibonaq(int a){
    if(a<2){
        if(arr[2]==0)arr[2]=arr[0]+arr[1];
        return arr[2];
    }
}
int main()
{
    memset((void*)arr,0,sizeof(arr));
    arr[0]=1;
    arr[1]=1;
    delete[] arr;
    return 0;
}