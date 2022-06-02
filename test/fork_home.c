#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int value=5;
int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        //表明是子进程
        value+=15;
    }
    else if(pid>0){
        wait(NULL);
        printf("parent: value=%d",value);
        exit(0);
    }
}