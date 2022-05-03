#include <stdio.h>
#include "graph.h"

//����ͼ��BFS��DFS
int GetShortestPath(Vertex V,Graph graph);
int main(){
    int NV;
    Graph graph;
    printf("�����붥����:");
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

//��Ȩͼ�����·��
int GetShortestPath(Vertex V,Graph graph){
    //��ʼ��dist �� path
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
        printf("%d��%d\t",dist[i],path[i]);
    }
}


//��Ȩͼ���·��
int Dijkstra(Graph graph,Vertex V){

}

