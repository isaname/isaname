#include<stdlib.h>
#include<stdio.h>
char  buffer [33];  //用于存放转换好的十六进制字符串，可根据需要定义长度
 
char  * inttohex( int  aa)
{
     static  int  i = 0;
     if  (aa < 16)             //递归结束条件 
     {
         if  (aa < 10)         //当前数转换成字符放入字符串 
             buffer[i] = aa +  '0' ;
         else
             buffer[i] = aa - 10 +  'A' ;
         buffer[i+1] =  '\0' ;  //字符串结束标志 
     }
     else
     {
         inttohex(aa / 16);   //递归调用 
         i++;                 //字符串索引+1 
         aa %= 16;            //计算当前值
         if  (aa < 10)         //当前数转换成字符放入字符串 
             buffer[i] = aa +  '0' ;
         else
             buffer[i] = aa - 10 +  'A' ;
     }
     return  (buffer);
}
int main(){
    FILE *fp=NULL;
    fp=fopen("/mnt/yuelu/.puzzle.txt","r+");
    long a=0; 
    fscanf(fp,"%d",&a);
    inttohex(a);
    printf("%d",a);
    printf("%s",buffer);
}