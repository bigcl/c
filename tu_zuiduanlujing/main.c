#include <stdio.h>
#include "graph.h"

//无向图的BFS和DFS
int GetShortestPath(Vertex V,Graph graph);
int main(){
    int NV;
    Graph graph;
    printf("请输入顶点数:");
    scanf("%d",&NV);
    graph = CreateGraph(NV);
    BuildNOWeightGraph(graph);
    int Visited[graph->Nv+1];
    for (int i = 1; i <= graph->Nv; ++i) {
        Visited[i] = 0;
    }
    DFS(graph,1,Visited);
    for (int i = 1; i <= graph->Nv; ++i) {
        Visited[i] = 0;
    }
    printf("\n");
    BFS(graph,1,Visited);




}

//无权图的最短路径
int GetShortestPath(Vertex V,Graph graph){
    //初始化dist 和 path
    int dist[graph->Nv+1],path[graph->Nv + 1];
    for(int i =1 ; i <= graph->Nv; i++){
        dist[i] = -1;
        path[i] = -1;
    }
    dist[V] = 0;
    Queue* queue = CreateQueue();
    AddQ(queue,V);
    while (!IsEmptyQ(queue)){
        V = DeleteQ(queue);
        for(PtrToAdjNode W = graph->adjList[V].firstEdge;W;W = W->next){
            if(dist[W->m] == -1){
                dist[W->m] = dist[V] + 1;
                path[W->m] = V;
                AddQ(queue,W->m);
            }
        }
    }
    for (int i = 1; i <= graph->Nv; i++) {
        printf("%d，%d\t",dist[i],path[i]);
    }
}


//有权图最短路径
int Dijkstra(Graph graph,Vertex V){

}

