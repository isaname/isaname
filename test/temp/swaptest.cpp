#include <iostream>
using namespace std;
int main()
{
    int a[2];
    a[0]=1;
    a[1]=2;
    for(int i=0;i<2;i++){
        cout<<a[i]<<" ";
    }
    swap(a[0],a[1]);
    for(int i=0;i<2;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}