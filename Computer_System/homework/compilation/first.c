#include "stdio.h"

#define H ?  //定义常数H
#define J ?  //定义常数J
int array1[H][J]; 
int array2[J][H]; 
void f(int x, int y) {

    array1[x][y] = x+2*y;
    array2[y][x]=y-x*x;

}

int main( )

{
    return 0;
}