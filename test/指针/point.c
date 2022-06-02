#include<stdio.h>
#include<stdlib.h>
void sort(int * x,int n){
    //使用选择排序
    int min=0;
    int pos=0;
    int temp=0;
    for(int i=0;i<n-1;i++){
        min=x[i];
        pos=i;
        for(int j=i;j<n;j++){
            if(min>x[j]){
                min=x[j];
                pos=j;
            }
        }
        temp=x[pos];
        x[pos]=x[i];
        x[i]=temp;
    }
}
int main(){
    int * x=(int *)malloc(40);
    printf("请输入十个数(以空格分割)");
    for(int i=0;i<10;i++){
        scanf("%d",x+i);
    }
    sort(x,10);
    for(int i=0;i<10;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}