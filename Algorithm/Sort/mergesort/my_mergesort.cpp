#include <iostream>
#include<cstdlib>
using namespace std;
void mergersort(int* a,int low,int mid,int hi){
    //默认此时a的左右两边有序
    int i=low;
    int j=mid+1;
    int temp[hi-low+1];
    int pos=0;
    while(i<=mid&&j<=hi){
        if(a[i]<a[j]){
            temp[pos]=a[i];
            pos++;
            i++;
        }else{
            temp[pos]=a[j];
            pos++;
            j++;
        }
    }
    while(i<=mid){
        temp[pos]=a[i];
        pos++;
        i++;
    }
    while(j<=hi){
        temp[pos]=a[j];
        pos++;
        j++;
    }
    //写回
    for(int k=0;k<=hi-low;k++){
        a[k+low]=temp[k];
    }
}
void merge(int *a,int low,int hi){
    if(hi>low){
        //表明至少有两个元素
        int mid=(hi+low)/2;
        merge(a,low,mid);
        merge(a,mid+1,hi);
        mergersort(a,low,mid,hi);
    }
}
int main()
{
    int seed=9;
    srand(seed);
    int *a=new int[10];
    for(int i=0;i<10;i++){
        a[i]=rand();
    }
    cout<<"排序前:";
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge(a,0,9);
    cout<<"排序后:";
    for(int  i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}