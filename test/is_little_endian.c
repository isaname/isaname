#include<stdio.h>
int main(){
    int num=1;
    unsigned char *point=(unsigned char *)&num;
    printf("%.x\n",point[0]);
    return 0;
}