#include<stdio.h>

int main(){
    int a=2;
    a=(a<<1)|0x8;
    printf("0x%x",a);
}