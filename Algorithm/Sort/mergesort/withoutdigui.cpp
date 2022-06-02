#include<iostream>
using namespace std;

void Merge(int r[],int r1[],int s,int m,int t)
{
    int i=s,j=m+1,k=s;
    while(i<=m&&j<=t)
    {
        if(r[i]<=r[j])
        {
            r1[k]=r[i];
            i++;
            k++;
        }
        else
        {
            r1[k]=r[j];
            j++;
            k++;
        }
    }
    if(i<=m)
    {
        while(i<=m)
        {
            r1[k]=r[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j<=t)
        {
            r1[k]=r[j];
            j++;
            k++;
        }
    }
}

void MergePass(int r[] ,int r1[] , int n, int h)
{
    int i=1;
    while(i<=n-2*h+1)
    {
        Merge(r,r1,i,i+h-1,i+2*h-1);
        i+=2*h;
    }
    if(i<n-h+1) Merge(r,r1,i,i+h-1,n);
    else for(int k=i; k<=n; k++)
    {
        r1[k]=r[k];
    }
}

void MergeSort(int r[],int r1[], int n)
{
    int h=1;
    while(h<n)
    {
        MergePass(r,r1,n,h);
        h*=2;
        MergePass(r1,r,n,h);
        h*=2;
    }
}

int main()
{
    int a[10000];
    int a1[10000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    MergeSort(a,a1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}