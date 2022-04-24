#include <stdio.h>
#include <malloc.h>
#include "queue.h"
#define OK 1
#define ERROR 0
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Status;
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

//定义边
typedef struct {
    Vertex v,w;         //边的两个顶点
}EdgeNode;

//定义邻接表的表节点
typedef struct {
    Vertex m;       //邻接的节点的编号
    struct Vnode* ptrVnode; //指向下一个节点
}Vnode;

//定义临界表的头结点
typedef struct {
    Vertex m;               //属于哪个顶点的链表
    struct Vnode* ptrVnode;     //指向链表第一个节点
    DataType data;
}ArcNode,AdjList[MaxVertexNum];

//定义顶点
typedef struct {
    Vertex m;       //节点编号
    int LinJinNum;  //邻近节点数目
}GraphNode;

//定义无向图
typedef struct {
    int NodeNum;//顶点数目
    GraphNode AllNode[MaxVertexNum];
    AdjList List;
}ALGraph;

//初始化图 顶点数目为NodeNum
Status createGraph(ALGraph *graph,int NodeNum){
    graph->NodeNum = NodeNum;
//    GraphNode allnode[graph->NodeNum];
//    graph->AllNode = allnode;
    //令邻接表的头结点指向为空 下标为i+1
    for (int i = 0; i < graph->NodeNum; i++) {
        graph->List[i].ptrVnode = NULL;
        graph->List[i].m = i + 1;
    }
    return OK;
}

//创建图
Status BuildGraph(ALGraph *graph) {
    for (int i = 0; i < graph->NodeNum; i++) {
        graph->AllNode[i].m = i + 1;
        printf("请输入节点数据:");
        scanf(" %c", &(graph->List[i].data));
        printf("请输入与节点%d相连节点数目\n", i + 1);
        scanf(" %d", &(graph->AllNode[i].LinJinNum));
        Vnode *temp = malloc(sizeof (Vnode));
        graph->List[i].ptrVnode = (Vnode *) malloc(sizeof(Vnode));
        temp = graph->List[i].ptrVnode;                           //使temp指向每个链表第一个元素
        scanf(" %d", &temp->m);
        temp->ptrVnode = NULL;
        graph->List[i].ptrVnode =  temp;
        for (int j = 1; j < (graph->AllNode[i].LinJinNum); j++) {
            Vnode *ptrNode = (Vnode *) malloc(sizeof(Vnode));
            scanf(" %d", &(ptrNode->m));
            ptrNode->ptrVnode = NULL;
            temp->ptrVnode = ptrNode;
            temp = temp->ptrVnode;
            if(j == graph->AllNode[i].LinJinNum - 1){
                temp->ptrVnode = NULL;
            }
        }
    }
}

//深度优先
void DFS(ALGraph graph,Vertex n,int* a){
    Vnode* PtrVnode;
    a[n] = 1;
    printf("%c\t",graph.List[n-1].data);
    for(PtrVnode = graph.List[n-1].ptrVnode;PtrVnode;PtrVnode = (Vnode *) PtrVnode->ptrVnode){
        n = PtrVnode->m;
        if(a[n] == 0 ) {
            DFS(graph, n, a);
        }
    }
}

void BFS(ALGraph graph,int n,int *Visited){
    struct QNode *qNode =CreateQueue();
    AddQ(qNode,n);
    Vnode *temp;
    int a;
    printf("%c\t",graph.List[n-1].data);
    Visited[n] = 1;
    while(!IsEmptyQ(qNode)){
        a = DeleteQ(qNode);
        for ( temp = graph.List[a-1].ptrVnode;temp;temp = temp->ptrVnode){
            if(Visited[temp->m] == 0){
                Visited[temp->m] = 1;
                printf("%c\t",graph.List[temp->m-1].data);
                AddQ(qNode,temp->m);
            }
        }
    }
};

void main(){
    ALGraph graph;
    createGraph(&graph,5);
    int a[graph.NodeNum + 1];       //0不储存
    for (int i = 0; i <= graph.NodeNum ; ++i) {
        a[i] = 0;
    }
    BuildGraph(&graph);
    printf("DFS:\n");
    DFS(graph,1,a);
    for (int i = 0; i <= graph.NodeNum ; ++i) {
        a[i] = 0;
    }
    printf("\nBFS：\n");
    BFS(graph,1,a);
}