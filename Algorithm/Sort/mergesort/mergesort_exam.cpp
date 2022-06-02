#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

void mergesort(int *A, int *temp, int left, int right)
{
    if(left<right){
        //表明还至少有两个元素
        int mid=(left+right)/2;
        mergesort(A,temp,left,mid);
        mergesort(A,temp,mid+1,right);
        //返回后,左右两边都有序
        int i=left;
        int j=mid+1;
        int pos=left;
        while(i<=mid&&j<=right){
            if(A[i]<A[j]){
                temp[pos]=A[i];
                pos++;
                i++;
            }else{
                temp[pos]=A[j];
                pos++;
                j++;
            }
        }
        //将剩余的添加上
        while(i<=mid){
            temp[pos]=A[i];
            i++;
            pos++;
        }
        while(j<=right){
            temp[pos]=A[j];
            j++;
            pos++;
        }
        for(int k=left;k<=right;k++){
            A[k]=temp[k];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a, *temp;
    a = new int[n];
    temp = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, temp, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    return 0;
}