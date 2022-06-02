#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 410;
int mp[N][N];
int ans[N];
int vis[N];
int start;
int end=0;
int n,m;
int cnt;
void init()
{
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(i==j)mp[i][j]=0;
      else    mp[i][j]=1;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    cnt=0;
}
 
void Reverse(int s,int e)
{
    while(s<e)
    {
     swap(ans[s],ans[e]);
     s++;
     e--;
    }
}
void kuozhan()
{
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&mp[end][i])
            {
                ans[cnt++]=i;
                end=i;
                vis[i]=1;
                flag=1;
                break;
            }
        }
        if(!flag)
        break;
    }
}
 
void hamiltun()
{
   start=1;
   for(int i=1;i<=n;i++)
       if(mp[1][i]){
           end=i;break;
       }
    vis[start]=1;
    vis[end]=1;
    ans[0]=start;
    ans[1]=end;
    cnt=2;
    while(1)
    {
      kuozhan();
      Reverse(0,cnt-1);
      swap(start,end);
      kuozhan();
      int mid=0;
      if(!mp[start][end])
      {
          for(int i=1;i<cnt-2;i++)
          {
            if(mp[ans[i]][end]&&mp[ans[i+1]][start])
            {
                mid=i+1;
                break;
            }
          }
          Reverse(mid,cnt-1);
          end=ans[cnt-1];
      }
      if(cnt==n)break;
      for(int i=1;i<=n;i++)
      {
          if(!vis[i])
          {
            int j;
            for(j=1;j<cnt-1;j++)
                if(mp[ans[j]][i])
                 {mid=j;break;}
            if(mp[ans[mid]][i]){
             end=i;mid=j;break;
            }
          }
      }
      start=ans[mid-1];
      Reverse(0,mid-1);
      Reverse(mid,cnt-1);
      ans[cnt++]=end;
      vis[end]=1;
    }
}
 
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        n*=2;
        int u,v;
        init();
        for(int i=1;i<=m;i++)
        {
          scanf("%d%d",&u,&v);
          mp[u][v]=mp[v][u]=0;
        }
        hamiltun();
        cout<<ans[0];
        for(int i=1;i<cnt;i++)
          printf(" %d",ans[i]);
        cout<<endl;
    }
    return 0;
}