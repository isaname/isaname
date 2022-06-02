#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#define M 3
#define K 2
#define N 3
int A[M][K]={
    {1,4},
    {2,5},
    {3,6}
};
int B[K][N]={{8,7,6},{5,4,3}};
int C[M][N];
struct v{
    int i;
    int j;
};//用来传输即将计算的i j 值
//由于修改的是不同位置的值,不需要考虑线程同步

void * jisuan(void * data){
    struct v* fuck=(struct v*)data;
    int i=fuck->i;
    int j=fuck->j;
    for(int k=0;k<K;k++){
        C[i][j]+=A[i][k]*B[k][j];
    }
    pthread_exit(NULL);//什么都不用返回,一切都已经处理好了
}
int main(){
    pthread_t id[M*N];
    memset((void*)C,0,sizeof(C));//初始化C
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            struct v* data=(struct v*)malloc(sizeof(struct v));
            data->i=i;
            data->j=j;
            pthread_create(id+i*N+j,NULL,jisuan,(void *) data);
        }
    }
    for(int i=0;i<M;i++){
        for(int  j=0;j<N;j++){
            pthread_join(id[i*N+j],NULL);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }//输出C数组的值
}