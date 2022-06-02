#include<time.h>
#include<stdio.h>
using namespace std;
void _time(){
    int n=1000000000;
    while (n--)
    {
        /* code */
    }
    
    printf("Elapsed time:%u sec.\n",clock());
}
int main(){
    long start=clock();
    int n=1000000000;
    while (n--)
    {
        /* code */
    }
    long mid=clock();
    _time();
    long end=clock();
    printf("%u %u %u\n",start,mid,end);
}