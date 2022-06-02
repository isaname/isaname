#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>

class option
{
private:
    Graph *G;
public:
// Start with some implementations for the abstract functions
    option(Graph *g)
    {
        G = g;
    }


    void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))   // Depth first search
    {
        PreVisit(v);
        G->setMark(v,VISITED);
        Visiting(v);
        for(int w=G->first(v);w<G->n();w=G->next(v,w)){
            if(G->getMark(w)==UNVISITED){
                DFS(w,PreVisit,PostVisit,Visiting);
            }
        }
        PostVisit(v);

    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
        int v,w;
        queue<int> que;
        que.push(start);
        G->setMark(start,VISITED);
        PreVisit(start);
        while(!que.empty()){
            v=que.front();
            que.pop();
            Visiting(v);
            for(w=G->first(v);w<G->n();w=G->next(v,w)){
                if(G->getMark(w)==UNVISITED){
                    G->setMark(w,VISITED);
                    PreVisit(w);
                    que.push(w);
                }
            }
            PostVisit(v);
        }

    }

    void Dijkstra1(int* D, int s)
    {
        int v,w;
        for(int i=G->first(s);i<G->n();i++){
            v=minVertex(D);
            if(D[v]==INFINITY)return ;
            G->setMark(v,VISITED);
            for(w=G->first(v);w<G->n();w=G->next(v,w))
                if(D[w]>(D[v]+G->weight(v,w)))
                    D[w]=D[v]+G->weight(v,w);
        }

    }
    void Dijkstra(int* D,int *temp, int s)
    {
        int v,w;
        for(int i=G->first(s);i<G->n();i++){
            v=minVertex(D);
            if(D[v]==INFINITY)return ;
            G->setMark(v,VISITED);
            for(w=G->first(v);w<G->n();w=G->next(v,w))
                if(D[w]>=(D[v]+G->weight(v,w))){
                    D[w]=D[v]+G->weight(v,w);
                    temp[w]=v;//在路径上,w的上一个节点是v
                }
        }

    }

    int minVertex(int* D)   // Find min cost vertex
    {
        int i, v = -1;
        // Initialize v to some unvisited vertex
        for (i = 0; i < G->n(); i++)
            if (G->getMark(i) == UNVISITED)
            {
                v = i;
                break;
            }
        for (i++; i < G->n(); i++) // Now find smallest D value
            if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
                v = i;
        return v;
    }

    void AddEdgetoMST(int v1, int v2)
    {
        cout << "Add edge " << v1 << " to " << v2 << "\n";
    }
    void Prim(int* D, int s)   // Prim's MST algorithm
    {
        int V[G->n()];
        int i,w;
        for(i=0;i<G->n();i++){
            int v=minVertex(D);
            G->setMark(v,VISITED);
            if(v!=s)
                AddEdgetoMST(V[v],v);
            if(D[v]==INFINITY)return ;
            for(w=G->first(v);w<G->n();w=G->next(v,w)){
                if(D[w]>G->weight(v,w)){
                    D[w]=G->weight(v,w);
                    V[w]=v;
                }
            }
        }
    }
    void topsort(int*D){
        int position=0;
        for(int i=0;i<G->n();i++){
            if(G->getInDegree(i)==0){
                D[position++]=i;
                G->setMark(i,VISITED);
            }
        }
        for(int i=position;i<G->n();i++){
            //遍历其他有入度的边
            
        }

    }
};

#endif // GRAPH_TEST_H_INCLUDED
