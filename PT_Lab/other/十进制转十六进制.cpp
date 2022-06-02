#include<stdio.h>
#include<string>
using namespace std;
char map[6]={'a','b','c','d','e','f'};
char* change(int inn){
    int fg=16;
    int count=1;
    while (inn/fg>0)
    {
        count++;
        fg*=16;
    }
    char str[count+1];
    int i=0;
    while(fg>16){
        fg/=16;
        if(inn/fg<10)
        str[i]=inn+48;
        else{
            str[i]=map[inn/fg-10];
        }
        inn=inn%fg;
        i++;
    }
    str[i]='\0';
    return str;
}
int main(){
    int inn=2;
    char * tar=change(inn);
    printf("%s\n",tar);
}