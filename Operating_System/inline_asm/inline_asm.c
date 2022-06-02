#include<stdio.h>

int main(){
    unsigned int low,high;
    asm volatile(
        "rdtsc":"=a"(low),"=d"(high)
    );
    printf("%u %u",high,low);
}