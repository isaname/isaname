#include <iostream>
#include<vector>
using namespace std;
struct node
{
    int v;
    int quan;
};

int main()
{
    int V;
    int E;
    cout<<"请输入点数:";
    cin>>V;
    cout<<"请输入边数:";
    cin>>E;
    //根据点数建一个数组
    vector<int> Graph_table[V];
    int a,b;
    for(int i=0;i<E;i++){
        cout<<"请输入各个边"<<endl;
        cout<<"边的起点:";
        cin>>a;
        cout<<"边的终点:";
        cin>>b;
        Graph_table[a].push_back(b);
    }
    return 0;
}
//如果需要带权值