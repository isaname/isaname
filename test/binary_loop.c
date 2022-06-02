#include<stdio.h>

int main(){
    int a=1;
    a=a<<31>>31;
    long count=0;
    while(a!=0){
        a--;
        count++;
    }
    printf("0x%lx\n",count);
}