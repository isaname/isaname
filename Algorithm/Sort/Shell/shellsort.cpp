#include <iostream>
#include<stdlib.h>
#define N 10
using namespace std;
void swap(int * a,int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void sort(int* a){
    int h=1;
    while(h<N/3)h=h*3+1;
    while(h>=1){
        for(int i=h;i<N;i++){
            for(int j=i;j>=h&&a[j]<a[j-h];j-=h)
                swap(a,j,j-h);
        }
        h/=3;
    }
}
int main()
{
    unsigned int seed=10;
    srand(seed);
    int * a=new int[N];//默认为10
    for(int i=0;i<N;i++){
        a[i]=rand();
    }
    sort(a);
    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}