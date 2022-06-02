#include <iostream>
using namespace std;

int main()
{
    int m=10;
    int n=10;
    cin>>m>>n;
    int a=1;
    long sum=1;
    while(a<n){
        sum*=a;
        a++;
    }
    int b=m+n-2;
    long temp=1;
    for(int i=0;i<n-1;i++){
        temp*=b;
        b--;
    }
    cout<<(temp/sum)<<endl;
    return 0;
}