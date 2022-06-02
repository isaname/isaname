#include<stdio.h>
#include<pthread.h>
int count=0;
//多线程与共享资源
void *mythread(void* a){
    printf("%s\n",a);
    int i;
    for(int i=0;i<120;i++){
        count++;
    }
    printf("%s:done\n",a);
    return NULL;
}
int main(){
    pthread_t p1,p2;
    pthread_create(&p1,NULL,mythread,(void*)"F");
    pthread_create(&p2,NULL,mythread,(void*)"K");
    pthread_join(p1,NULL);//等待p1
    pthread_join(p2,NULL);//等待p2
    printf("done:count is %d\n",count);
    return 0;
}