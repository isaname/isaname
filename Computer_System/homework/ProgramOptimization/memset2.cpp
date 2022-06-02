#include <iostream>
using namespace std;
void* memset(void* s,int c,size_t n){
    int k=sizeof(long);
    unsigned char *schar=s;//设置一个字符指针
    unsigned long *sforlong=s;//设置一个long型指针
    long forwrite;
    unsigned char *slong=&forwrite;
    int cnt=0;
    for(int i=0;i<k;i++){
        *slong=(unsigned char)c;
        slong++;
    }
    if(n<k){
        while(cnt++<n){
            *schar++=(unsigned char)c;
        };
    }
    else {   //地址对齐
        while(schar%k!=0){
            *schar=(unsigned char)c;
            schar++;
            cnt++;
        }
        while(cnt+k-1<n){
            //long 型写入
            cnt+=k;
            *sforlong=forwrite;
            sforlong++;
        }
        while(cnt++<n){
            //将剩余的写入
            *schar++=(unsigned char)c;
        }
    }
}
