#include<stdio.h>
#include<pthread.h>
#define MAX 100
int buffer[MAX];
int fill=0;
int use=0;
pthread_cond_t empty,full;
pthread_mutex_t mutex;
int loop;
int count=0;
void put(int value){
    buffer[fill]=value;
    fill=(fill+1)%MAX;
    count++;
}
int get(){
    int tmp=buffer[use];
    use=(use+1)%MAX;
    count--;
    return tmp;
}
void *producer(void *args){
    int i;
    for(i=0;i<loop;i++){
        pthread_mutex_lock(&mutex);
        if(count==1){
            pthread_cond_wait(&full,&mutex);
        }
        put(i);
    }
}
void* consumer(void* args){

}
int main(){
    
}