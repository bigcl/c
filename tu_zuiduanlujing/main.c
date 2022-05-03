#include <stdio.h>
#include "graph.h"

//无向图的BFS和DFS
int GetShortestPath(Vertex V,Graph graph);
//单源有权图的最短路径(Dijkstra算法)
void Dijkstra(Graph graph,Vertex V);
//多源有权图
void Floyd(Graph graph);
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
//    BuildGraph(graph);
//    Floyd(graph);
//    Dijkstra(graph,1);
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



void Floyd(Graph graph){
    //定义距离的矩阵和路径矩阵
    int D[graph->Nv + 1][graph->Nv + 1],Path[graph->Nv + 1][graph->Nv + 1];

    //初始化矩阵
    for(int i = 1;i <= graph->Nv; i++){
        for(int j = 1; j <= graph->Nv;j++){
            Path[i][j] = -1;
            if(i == j){
                D[i][j] = 0;
            } else D[i][j] = 9999;
        }
    }

    //给每个顶点的临边赋值
    for(int V = 1;V <= graph->Nv;V++){
        for(PtrToAdjNode W = graph->adjList[V].firstEdge;W;W = W->next){
            D[V][W->m] = W->wight;
            Path[V][W->m] = V;
        }
    }

    //下面开始将每个顶点回收
    for(int N = 1;N <= graph->Nv;N++){
        for(int i = 1; i<= graph->Nv;i++){
            for(int j = 1;j <= graph->Nv;j++){
                if(D[i][j] > D[i][N] + D[N][j]){
                    D[i][j] = D[i][N] + D[N][j];
                    Path[i][j] = N;
                }
            }
        }
    }
    printf("到每个点最近距离为：\n");
    for(int i = 1;i <= graph->Nv;i++){
        for(int j = 1;j <= graph->Nv;j++){
            printf("%d\t",D[i][j]);
        }
        printf("\n");
    }
}
