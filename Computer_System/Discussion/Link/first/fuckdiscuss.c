//假设有六门学科 依次是:语文 数学 英语 物理 化学 生物
#include<stdio.h>
#include<stdlib.h>
char *course[]={"语文","数学","英语","物理","化学","生物"};
//计算分数段的函数
int* scale(int **a,int n,int courseid){
    int* res=(int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++){
        res[i]=0;
    }
    for(int i=0;i<n;i++){
        int temp=a[i][courseid];
        if(temp>=80){
            res[4]+=1;
        }else if(temp>=60){
            res[3]+=1;
        }else if(temp>=40){
            res[2]+=1;
        }else if(temp>=20){
            res[1]+=1;
        }else res[0]+=1;
    }
    return res;
}

//计算班级里的最值
//计算最高分
int max_class(int **a,int n){
    int max=0;
    int temp=0;
    for(int i=0;i<n;i++){
        temp=0;
        for(int j=0;j<6;j++){
            temp+=a[i][j];
        }
        if(temp>max){
            max=temp;
        }
    }
    return max;
}
//计算班级的最低分
int min_class(int **a,int n){
    int min=600;
    int temp=0;
    for(int i=0;i<n;i++){
        temp=0;
        for(int j=0;j<6;j++){
            temp+=a[i][j];
        }
        if(temp<min){
            min=temp;
        }
    }
    return min;
}
//计算课程的最值
//最大值
int max_course(int **a,int n,int courseid){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<a[i][courseid])max=a[i][courseid];
    }
    return max;
}
//计算课程最小值
int min_course(int **a,int n,int courseid){
    int min=0;
    for(int i=0;i<n;i++){
        if(min<a[i][courseid])min=a[i][courseid];
    }
    return min;
}

//计算排名
//全科排名
int *ranking_all(int **a,int n){
    int temp[n];
    
    for(int i=0;i<n;i++){
        temp[i]=0;
        for(int j=0;j<6;j++){
            temp[i]+=a[i][j];
        }
    }

    int *res=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(temp[j]>temp[i]){
                count++;
            }
        }
        res[i]=count;
    }
    return res;
}
//单科排名
int* ranking(int **a,int n,int courseid){
    int temp[n];
    for(int i=0;i<n;n++){
        temp[i]=a[i][courseid];
    }
    int *res=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(temp[j]>temp[i]){
                count++;
            }
        }
        res[i]=count;
    }
    return res;
}
//计算优势课程
void goodcourse(int *a){
    int it=0;
    int max=a[0];
    for(int i=1;i<6;i++){
        if(a[i]>max){
            a[i]=max;
            it=i;
        }
    }
    printf("优势科目是:%s",course[it]);
}