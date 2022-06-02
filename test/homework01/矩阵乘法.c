#include<stdio.h>
int main(){
    int hang=0;
    int lie=0;
    printf("请输入行数:\n");
    scanf("%d",&hang);
    printf("请输入列数:\n");
    scanf("%d",&lie);
    int a[hang][lie];
    int b[lie][hang];
    printf("请按行输入a矩阵\n");
    int res[hang][lie];
    for(int i=0;i<hang;i++){
        for(int j=0;j<lie;j++){
            scanf("%d",&(a[i][j]));
            res[i][j]=0;
        }
    }
    printf("请按行输入b矩阵\n");
    for(int i=0;i<lie;i++){
        for(int j=0;j<hang;j++){
            scanf("%d",&(b[i][j]));
        }
    }
    
    for(int i=0;i<hang;i++){
        for(int j=0;j<lie;j++){
            for(int k=0;k<lie;k++){
                res[i][j]+=a[i][k]*b[k][i];
            }
        }
    }
    printf("最终结果是:\n");
    for(int i=0;i<hang;i++){
        for(int j=0;j<lie;j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
}