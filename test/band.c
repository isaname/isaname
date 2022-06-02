#include<stdio.h>
int bang(int x) {
x = (x>>1)|x;
x = (x>>2)|x;
x = (x>>4)|x;
x = (x>>8)|x;
x = (x>>16)|x;
return ~(x & 1)+2;
}
int main(){
    printf("%d\n",bang(0x00002000));
}