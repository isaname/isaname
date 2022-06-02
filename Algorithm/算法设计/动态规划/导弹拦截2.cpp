#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[100001];//存放导弹高度
int b[100001];//存放当前最长非递增子序列长度
int m[100001];//存放导弹拦截系统的拦截高度
//求两个数中的最大值
int max(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
}
//求一个数组中的最长非递增子序列
int getLIS(int n)
{
	//b[i]表示从第一个元素到第i个元素的最长非递增子序列的长度。
    for(int i=1;i<=n;i++)
        b[i]=1;
    //动态规划
    //b[i]=max{b[i],b[j]+1}(j<i&&a[j]>=a[i])
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]<=a[j]){
                b[i]=max(b[i],b[j]+1);
            }
        }
    }
    //求b数组的最大值，即为整个a数组的最长非递增子序列的长度
    int max=b[1];
    for(int i=2;i<=n;i++)
      if(max<b[i])
         max=b[i];
    return max;
}
int minSystem(int n)
{
    m[1]=a[1];//第一个导弹拦截系统
    int k=1;//导弹拦截系统的数目
    for(int i=2;i<=n;i++){
        int flag=0;//用来标记
        for(int j=1;j<=k;j++){
            if(a[i]<=m[j])//说明可以拦截
            {
                if(flag==0)//说明这是可以拦截的第一个系统
                    flag=j;
                if(flag!=0&&m[flag]>=m[j])//如果不是第一个拦截系统但是比拟打算拦截这个导弹的系统的拦截高度还要低
                    flag=j;//更新flag
            }
        }
        if(flag==0)//说明没有系统可以拦截
        {
            k++;//再增加一个拦截系统
            m[k]=a[i];//拦截系统的高度就是当前导弹的高度
        }
        else{
            //可以拦截，更新代价最小的系统
            m[flag]=a[i];
        }
    }
    return k;
}
int main()
{
    int n=0;
    char ch;
    //把n个数都输入进去
    while(scanf("%d",&a[n])!=-1){
        n++;
        ch=getchar();
        if(ch=='\n')
            break;
    }
    cout<<getLIS(n)<<endl;
    cout<<minSystem(n);
    return 0;
}
