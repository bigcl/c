#include <stdio.h>
#include "graph.h"

//无向图的BFS和DFS
int GetShortestPath(Vertex V,Graph graph);
//单源有权图的最短路径(Dijkstra算法)
void Dijkstra(Graph graph,Vertex V);
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


//单源有权图最短路径
void Dijkstra(Graph graph,Vertex V){
    //定义dist和path
    int dist[graph->Nv + 1],path[graph->Nv + 1],minNum = 1000,collected[graph->Nv+1],vertex = -1;

    //初始化dist和path
    for(int i = 1;i <= graph->Nv;i++){
        dist[i] = 5000;
        path[i] = -1;
        collected[i] = 0;
    }
    dist[V] = 0;
    path[V] = V;
    collected[V] = 1;
    //将与原点相连的数赋初始值
    for(PtrToAdjNode W = graph->adjList[V].firstEdge;W;W = W->next){
        dist[W->m] = W->wight;
        path[W->m] = V;
    }
    while (1) {
        vertex = -1,minNum = 1000;
        //将未收录dist中最小的值收录进来
        for (int i = 1; i <= graph->Nv; i++) {
            if (collected[i] == 0 && dist[i] < minNum) {
                minNum = dist[i];
                vertex = i;
            }
        }
        if(vertex == -1) break;
        collected[vertex] = 1;

        //对收录进来的顶点临边(未收录)进行更新
        for(PtrToAdjNode W = graph->adjList[vertex].firstEdge;W;W = W->next){
            if(collected[W->m] == 0 && dist[vertex] + W->wight < dist[W->m]){
                dist[W->m] = dist[vertex] + W->wight;
                path[W->m] = vertex;
            }
        }
    }

    for(int i = 1; i <= graph->Nv;i++){
        printf("%d,%d\t",dist[i],path[i]);
    }

}

