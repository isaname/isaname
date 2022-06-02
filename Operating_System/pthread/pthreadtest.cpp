    #include<iostream>
    #include<pthread.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<inttypes.h>
    using namespace std;
    int64_t end,now,start,sum;
     
    pthread_mutex_t now_t;
     
    void *add(void* arg){
        while(1){
           pthread_mutex_lock(&now_t);
           if(now>end){
              pthread_mutex_unlock(&now_t);
           }
           sum+=now;
           now++;
           pthread_mutex_unlock(&now_t);
        }
    }
     
     
    int main(int argc,char *argv[]){
        sum=0;
        now=0;
        if(argc != 3){
           printf("参数 error\n");
           return 1;
        }
        int num_of_thread=0;
        num_of_thread=atoi(argv[2]);
        end=atoi(argv[1]);
        pthread_t tid[num_of_thread];
        for(int i = 0;i < num_of_thread;i++){
          pthread_create(&tid[i],NULL,add,NULL);
        }
        for(int i=0;i<num_of_thread;i++){
           pthread_join(tid[i],NULL);//等待线程结束
        }
        printf("sum = %lld\n",sum);
		return 0;
	}
