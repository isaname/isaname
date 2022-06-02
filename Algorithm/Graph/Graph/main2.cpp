#include "grlist.h"
#include "grmat.h"
#include "Graph_test.h"
#include<iomanip>
#include<cmath>
int main(){
    int n,m;
    cin>>n>>m;
    int x,y,z;
    Graph * g=new Graphm(n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        g->setEdge(x-1,y-1,z);
    }//图的初始化完成
    int source,destination;
    cin>>source>>destination;
    source--;
    destination--;
    if(source==destination){
        cout<<100<<endl;
        return 0;
    }
    int *D=new int[n];
    int *temp=new int[n];
    option* it=new option(g);
    for (int i = 0; i < g->n(); i++){ // Initialize
            D[i] = INFINITY;
            temp[i]=-1;
    }
    D[source] = 0;
    it->Dijkstra(D, temp,source);
    long double res=100;
    int i=destination;
    while(i!=source){
        res=res*100/(100-(g->weight(temp[i],i)));
        i=temp[i];
    }
    cout<<fixed<<setprecision(8)<<res<<endl;
}