#include<stdio.h>

int main(){
    int a[4][3]={
        {1,2,3},
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };
    // int rows = sizeof(arr) / sizeof(arr[0]);
    // int columns = sizeof(arr[0]) / sizeof(arr[0][0]);
    for(int i=0;i<sizeof(a)/sizeof(*a);i++){
        for(int j=0;j<sizeof(*a)/sizeof(**a);j++){
            printf("%d",a[i][j]);
        }
    }
}