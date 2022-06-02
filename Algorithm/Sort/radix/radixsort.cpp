#include <iostream>
#include<cstdlib>
#include<stdlib.h>
#define N 100
using namespace std;
void radixsort(int * a){

}
int main()
{
    int *a =new int[N];
    int seed=10;
    srand(seed);
    for(int i=0;i<N;i++){
        a[i]=rand();
    }
    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}