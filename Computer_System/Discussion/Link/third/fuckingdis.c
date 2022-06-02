#include<stdio.h>
#define min 5
#define max 20
int fg1=0;
int fg2=0;
int fg3=0;
int fg4=0;
int strlen(char* a){
    for(int i=0;i<max+1;i++){
        if(a[i]=='0')return i;
    }
    return -1;
}
int islower(char a){
    if(a>=97&&a<123)return 1;
    return 0;
}
int ishigher(char a){
    if(a>=65&&a<91)return 1;
    return 0;
}
int isnum(char a){
    if(a>=48&&a<58)return 1;
    return 0;
}
int issim(char a){
    switch (a)
    {
    case 64:
        return 1;
        break;
    case 35:
        return 1;
    case 45:
        return 1;
    case 37:
        return 1;
    case 36:
        return 1;
    case 91:
        return 1;
    case 93:
        return 1;
    default:
        break;
    }
    return 0;
}
int main(){
    char pwd[max+1];
    while(1){
        int fg=0;
        //循环读取单个字符
        scanf("%s",pwd);
        if(strlen(pwd)==-1){
            printf("密码过长!\n");
            break;
        }
        int len=strlen(pwd);
        for(int i=0;i<len;i++){
            if(ishigher(pwd[i])){fg1=1;break;};
            if(islower(pwd[i])){fg2=1;break;};
            if(isnum(pwd[i])){fg3=1;break;};
            if(issim(pwd[i])){fg4=1;break;};
            
        }
        if(fg1&&fg2&&fg3&&fg4){
            printf("密码设置成功");
            break;
        }else{
            fg1=0;fg2=0;fg3=0;fg4=0;
        }
    }
}