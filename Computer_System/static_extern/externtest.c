#include<stdio.h>
#include"extern.c"
int x=0;
extern int y;
int main(int argc, char const *argv[])
{
    printf("%d\n",y);
    return 0;
}
