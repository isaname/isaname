#include<stdio.h>

int main(){
    int a=1,b=2,c=0;
    asm(
        "addl %2, %0"
        : "=g"(c)
        : "0"(a),"g"(b)
        : "memory");
    printf("现在c是:%d\n",c);
    return 0;
}