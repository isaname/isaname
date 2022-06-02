#include<stdio.h>
#include<string.h>
int main(){
    char str[3][100];
    printf("请输入第一个字符串\n");
    scanf("%s",str[0]);
    printf("请输入第二个字符串\n");
    scanf("%s",str[1]);
    printf("请输入第三个字符串\n");
    scanf("%s",str[2]);
    char* res=str[0];
    for(int i=1;i<3;i++){
        if(strcmp(res,str[i])<0)res=str[i];
    }
    printf("最大字符串为:%s\n",res);
}