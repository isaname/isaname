#include<stdio.h>
struct fuck{
    int id;
    int fenshu;
}a;
int main(){
    a.fenshu =100;
    a.id=10;
    struct fuck* temp=&a;
    void* fuck= (void*)temp+4;
    printf("%d\n",*((int*)fuck));
}