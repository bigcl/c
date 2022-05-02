//
// Created by joker on 2022/5/1.
//

#ifndef TU_ZUIDUANLUJING_GRAPH_H
#define TU_ZUIDUANLUJING_GRAPH_H
#include "queue.h"
#include <malloc.h>
#define MAXVertexNUM 100

typedef int Vertex;     //�����±�
typedef char DataType;
//�����
typedef struct{
    Vertex v1, v2;
    int weight;
}ENode, *PtrToENode;

//����߼���
typedef PtrToENode Edge;

typedef struct AdjNode *PtrToAdjNode;

//�����ڽӱ�ڵ�
struct AdjNode{
    Vertex m;           //�ڵ��±꣨��ͷ��
    int wight;
    PtrToAdjNode next;
};

//�����ڽӱ�ͷ���
typedef struct{
    DataType data;
    PtrToAdjNode firstEdge;
}Vnode,AdjList[MAXVertexNUM + 1];

//����ͼ�ڵ�
typedef struct {
    int Nv;         //��������
    int Ne;          //�������
    AdjList adjList;    //�����ڽӱ�
}GNode;

typedef GNode *PtrToGNode;
typedef PtrToGNode Graph;

//����һ��ͼ����ʼ�� , �ǵý�AdjList��firstEdge��Ϊ��ֵ
Graph CreateGraph(int VertexNum){
    Vertex V, W;
    Graph graph;
    graph = (Graph)malloc(sizeof (GNode));
    graph->Nv = VertexNum;
    graph->Ne = 0;

    //��ʼ���ڽӱ�
    for(int i = 1; i <= graph->Nv;i++){
        graph->adjList[i].firstEdge = NULL;
    }
    return graph;
}

//��������ͼ�ı�  ÿ����ͷ������
Graph InsertEdge(Graph graph,int v1,int v2,int weight){
    PtrToAdjNode Edge = (PtrToAdjNode)malloc(sizeof (struct AdjNode));
    Edge->m = v2;
    Edge->wight = weight;
    Edge->next = graph->adjList[v1].firstEdge;
    graph->adjList[v1].firstEdge = Edge;
    return graph;
}

//��������ͼ�ı�  ÿ����ͷ������
Graph InsertEdge1(Graph graph,int v1,int v2,int weight){
    PtrToAdjNode Edge1 = (PtrToAdjNode)malloc(sizeof (struct AdjNode));
    Edge1->m = v2;
    Edge1->wight = weight;
    Edge1->next = graph->adjList[v1].firstEdge;
    graph->adjList[v1].firstEdge = Edge1;

    //�����<v2,v1>
    PtrToAdjNode Edge2 = (PtrToAdjNode)malloc(sizeof (struct AdjNode));
    Edge2->m = v1;
    Edge2->wight = weight;
    Edge2->next = graph->adjList[v2].firstEdge;
    graph->adjList[v2].firstEdge = Edge2;
    return graph;
}

int* InitVisited(int *visited,int num){
    for(int i = 1; i <= num ; i++){
        visited[i] = 0;
    }
}



//����ͼ
Graph BuildNOWeightGraph(Graph graph){
    int v1,v2,weight;
    printf("������ͼ����");
    scanf("%d",&(graph->Ne));           //�������
    for(int E = 0; E < graph->Ne; E++){
        printf("������ߵ���Ϣ\n");
        scanf("%d %d %d",&v1,&v2,&weight);
        graph = InsertEdge1(graph,v1,v2,weight);
    }
}

//����ͼ
Graph BuildGraph(Graph graph){
    int v1,v2,weight;
    printf("������ͼ����");
    scanf("%d",&(graph->Ne));           //�������
    for(int E = 0; E < graph->Ne; E++){
        printf("������ߵ���Ϣ\n");
        scanf("%d %d %d",&v1,&v2,&weight);
        graph = InsertEdge(graph,v1,v2,weight);
    }
}

void Visit(Vertex adjV){
    printf("%d\t",adjV);
}

void DFS(Graph graph, Vertex v,int *Visited){
    Visited[v] = 1;
    Visit(v);
    for(PtrToAdjNode W = graph->adjList[v].firstEdge;W;W = W->next){
        if(Visited[W->m] == 0){
            DFS(graph,W->m,Visited);
        }
    }
}

void BFS(Graph graph,Vertex V,int *Visited){
    Queue* queue = CreateQueue();
    AddQ(queue,V);
    Visited[V] = 1;
    Visit(V);
    while (!IsEmptyQ(queue)){
        V = DeleteQ(queue);
        for(PtrToAdjNode W = graph->adjList[V].firstEdge;W;W = W->next){
            if(Visited[W->m] == 0){
                AddQ(queue,W->m);
                Visited[W->m] = 1;
                Visit(W->m);
            }
        }
    }
}

#endif //TU_ZUIDUANLUJING_GRAPH_H
