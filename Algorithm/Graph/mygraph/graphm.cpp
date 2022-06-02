#include"graph.h"
class Graphm:public Graph{
private:
    int numvertex,numedge;
    int* mark;
    int** matrix;
public:
    Graphm(int numVert){Init(numVert);}
    ~Graphm(){
        delete[] mark;
        for(int i=0;i<numvertex;i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void Init(int n){

    }
    int n(){}
    int e(){}
    int first(int v){
        for(int i=0;i<numvertex;i++)if(matrix[i]!=0)return i;
        return numvertex;
    }
    int next(int v,int w){
        //返回w之后的节点
        for(int i=w+1;i<numvertex;i++)if(matrix[i]!=0)return i;
        return numvertex;
    }
    void setEdge(int v1,int v2,int wt){}
};