#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int x=70;
    int seu=fork();
    if(seu<0){
        //表示进程创建不成功
        printf("error:x=%d/n",x);
    }else if(seu==0){
        //表示当前为子进程
        x=10;
        printf("child:x=%d\n",x);
    }else{
        //表示当前为父进程
        x=100;
        printf("parent:x=%d\n",x);
    }
}