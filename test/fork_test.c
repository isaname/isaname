#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
    printf("hello,%d is running\n",getpid());
    int rc=fork();
    if(rc<0){
        //表示开启子进程失败
        printf("失败(%d)\n",getpid());

    }else if(rc==0){
        sleep(1);
        printf("hi,I am child of pid:%d(%d)\n",getppid(),getpid());

    }else{
        wait(NULL);
        printf("hello,I am father(%d)\n",getpid());
    }
    return 0;
}