#include <stdio.h>
#include "graph.h"

//����ͼ��BFS��DFS
int GetShortestPath(Vertex V,Graph graph);
//��Դ��Ȩͼ�����·��(Dijkstra�㷨)
void Dijkstra(Graph graph,Vertex V);
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


//��Դ��Ȩͼ���·��
void Dijkstra(Graph graph,Vertex V){
    //����dist��path
    int dist[graph->Nv + 1],path[graph->Nv + 1],minNum = 1000,collected[graph->Nv+1],vertex = -1;

    //��ʼ��dist��path
    for(int i = 1;i <= graph->Nv;i++){
        dist[i] = 5000;
        path[i] = -1;
        collected[i] = 0;
    }
    dist[V] = 0;
    path[V] = V;
    collected[V] = 1;
    //����ԭ��������������ʼֵ
    for(PtrToAdjNode W = graph->adjList[V].firstEdge;W;W = W->next){
        dist[W->m] = W->wight;
        path[W->m] = V;
    }
    while (1) {
        vertex = -1,minNum = 1000;
        //��δ��¼dist����С��ֵ��¼����
        for (int i = 1; i <= graph->Nv; i++) {
            if (collected[i] == 0 && dist[i] < minNum) {
                minNum = dist[i];
                vertex = i;
            }
        }
        if(vertex == -1) break;
        collected[vertex] = 1;

        //����¼�����Ķ����ٱ�(δ��¼)���и���
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

