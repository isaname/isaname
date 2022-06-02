#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
 
 int main(){
     //打开一个文件流
     int out=-1;
     char buffA[]={'a','A','\0'};
     char buffB[]={'b','B','\0'};
     int in=-1;
     
     out = open("data.txt",O_WRONLY);
     int state=fork();
     if(state>0){
        sleep(1);
         write(out,&buffB,2);
     }else 
     if(state==0){
         //表示当前在子进程
         write(out,&buffA,2);//写一个
     }
     close(out);
 }