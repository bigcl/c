//
// Created by joker on 2022/5/1.
//

#ifndef TU_ZUIDUANLUJING_GRAPH_H
#define TU_ZUIDUANLUJING_GRAPH_H
#include "queue.h"
#include <malloc.h>
#define MAXVertexNUM 100

typedef int Vertex;     //顶点下标
typedef char DataType;
//定义边
typedef struct{
    Vertex v1, v2;
    int weight;
}ENode, *PtrToENode;

//定义边集合
typedef PtrToENode Edge;

typedef struct AdjNode *PtrToAdjNode;

//定义邻接表节点
struct AdjNode{
    Vertex m;           //节点下标（狐头）
    int wight;
    PtrToAdjNode next;
};

//定义邻接表头结点
typedef struct{
    DataType data;
    PtrToAdjNode firstEdge;
}Vnode,AdjList[MAXVertexNUM + 1];

//定义图节点
typedef struct {
    int Nv;         //定义结点数
    int Ne;          //定义边数
    AdjList adjList;    //定义邻接表
}GNode;

typedef GNode *PtrToGNode;
typedef PtrToGNode Graph;

//创建一个图并初始化 , 记得将AdjList的firstEdge赋为空值
Graph CreateGraph(int VertexNum){
    Vertex V, W;
    Graph graph;
    graph = (Graph)malloc(sizeof (GNode));
    graph->Nv = VertexNum;
    graph->Ne = 0;

    //初始化邻接表
    for(int i = 1; i <= graph->Nv;i++){
        graph->adjList[i].firstEdge = NULL;
    }
    return graph;
}

//插入有向图的边  每次往头部插入
Graph InsertEdge(Graph graph,int v1,int v2,int weight){
    PtrToAdjNode Edge = (PtrToAdjNode)malloc(sizeof (struct AdjNode));
    Edge->m = v2;
    Edge->wight = weight;
    Edge->next = graph->adjList[v1].firstEdge;
    graph->adjList[v1].firstEdge = Edge;
    return graph;
}

//插入无向图的边  每次往头部插入
Graph InsertEdge1(Graph graph,int v1,int v2,int weight){
    PtrToAdjNode Edge1 = (PtrToAdjNode)malloc(sizeof (struct AdjNode));
    Edge1->m = v2;
    Edge1->wight = weight;
    Edge1->next = graph->adjList[v1].firstEdge;
    graph->adjList[v1].firstEdge = Edge1;

    //插入边<v2,v1>
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



//建造图
Graph BuildNOWeightGraph(Graph graph){
    int v1,v2,weight;
    printf("请输入图边数");
    scanf("%d",&(graph->Ne));           //输入边数
    for(int E = 0; E < graph->Ne; E++){
        printf("请输入边的信息\n");
        scanf("%d %d %d",&v1,&v2,&weight);
        graph = InsertEdge1(graph,v1,v2,weight);
    }
}

//建造图
Graph BuildGraph(Graph graph){
    int v1,v2,weight;
    printf("请输入图边数");
    scanf("%d",&(graph->Ne));           //输入边数
    for(int E = 0; E < graph->Ne; E++){
        printf("请输入边的信息\n");
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
