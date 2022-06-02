#include<stdio.h>
#include<stdlib.h>
int* fuck(){
    int* a=(int*)malloc(sizeof(int)*2);
    a[1]=2;
    a[0]=1;
    return a;
}
int main(){
    int* a=fuck();
    printf("%d %d",a[0],a[1]);
}