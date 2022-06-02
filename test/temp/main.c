#include"factorial.h"
#include<stdio.h>
int main(){
    int a;
    printf("请输入:\n");
    scanf("%d",&a);
    printf("结果为:%d\n",factorial(a));
    return 0;
}