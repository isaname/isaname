#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,k;
    cin>>n>>m>>k;
    queue<int>q1,q2;
    for(int i=1;i<=n;i++)q1.push(i);
    for(int i=1;i<=m;i++)q2.push(i);
    while(k--)
    {
        cout<<q1.front()<<" "<<q2.front()<<endl;
        q1.push(q1.front());
        q2.push(q2.front());
        q1.pop();
        q2.pop();
    }
    return 0;
}
