#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int state=fork();
    if(state<0){
        printf("error!");
    }else if(state==0){
        char * myargs[3];
        myargs[0]=strdup("ls");
        myargs[1]=strdup(".");
        myargs[2]=NULL;
        execvp(myargs[0],myargs);
    }else{
        wait(NULL);
    }
}