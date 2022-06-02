#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("arg:%d",argc);
    for(int i=1;i<argc;i++)
    printf("%s",argv[i]);
    return 0;
}
