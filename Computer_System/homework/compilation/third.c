#include <stdio.h>
int frac(int a)

{

if(a<2) return a=a*a;//无限递归?

return frac(a-2)+a;

}

int sum(int a,int b)

{

int c=frac(a+b);

return c+c+b;

}

int main()

{

int i=10,j=6;

int k=sum(i++,j-i);


return 0;

}