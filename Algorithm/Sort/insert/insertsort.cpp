#include <iostream>
#define N 100
using namespace std;
void insertsort(int * a){
    for(int i=1;i<N;i++){
        //i指向未排序的序列的首元素
        int key=a[i];
        int k=i-1;
        //如果key 比有序序列中的值都小怎么办?
        for(;k>-1;k--){
            if(key<a[k])a[k+1]=a[k];
            else break;
        }
        a[k+1]=key;
    }
}
int main()
{
    int *a =new int[N];
    for(int i=0;i<N;i++){
        a[i]=100-i;
    }
    insertsort(a);
    for(int  i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    delete[] a;
    return 0;
}