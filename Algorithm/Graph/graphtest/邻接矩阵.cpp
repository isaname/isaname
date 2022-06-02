#include<iostream>
using namespace std;
int main(){
    int v;
    int e;
    cout<<"请输入顶点个数:";
    cin>>v;
    cout<<"请输入边数:";
    cin>>e;
    int Graph_ju[v][v];
    cout<<"请输入边:";
    for(int i=0;i<v;i++)
        for(int x=0;x<v;x++)
            Graph_ju[i][x]=0;
    int a;
    int b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        Graph_ju[a][b]=1;
        Graph_ju[b][a]=1;
    }
    for(int i=0;i<v;i++){
        for(int x=0;x<v;x++){
            cout<<Graph_ju[i][x]<<" ";
        }
        cout<<endl;
    }
}
//如果需要带权,把一改成权