#include <stdio.h>
#include <malloc.h>
#include "queue.h"
#define OK 1
#define ERROR 0
#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
typedef int Status;
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */

//�����
typedef struct {
    Vertex v,w;         //�ߵ���������
}EdgeNode;

//�����ڽӱ�ı�ڵ�
typedef struct {
    Vertex m;       //�ڽӵĽڵ�ı��
    struct Vnode* ptrVnode; //ָ����һ���ڵ�
}Vnode;

//�����ٽ���ͷ���
typedef struct {
    Vertex m;               //�����ĸ����������
    struct Vnode* ptrVnode;     //ָ�������һ���ڵ�
    DataType data;
}ArcNode,AdjList[MaxVertexNum];

//���嶥��
typedef struct {
    Vertex m;       //�ڵ���
    int LinJinNum;  //�ڽ��ڵ���Ŀ
}GraphNode;

//��������ͼ
typedef struct {
    int NodeNum;//������Ŀ
    GraphNode AllNode[MaxVertexNum];
    AdjList List;
}ALGraph;

//��ʼ��ͼ ������ĿΪNodeNum
Status createGraph(ALGraph *graph,int NodeNum){
    graph->NodeNum = NodeNum;
//    GraphNode allnode[graph->NodeNum];
//    graph->AllNode = allnode;
    //���ڽӱ��ͷ���ָ��Ϊ�� �±�Ϊi+1
    for (int i = 0; i < graph->NodeNum; i++) {
        graph->List[i].ptrVnode = NULL;
        graph->List[i].m = i + 1;
    }
    return OK;
}

//����ͼ
Status BuildGraph(ALGraph *graph) {
    for (int i = 0; i < graph->NodeNum; i++) {
        graph->AllNode[i].m = i + 1;
        printf("������ڵ�����:");
        scanf(" %c", &(graph->List[i].data));
        printf("��������ڵ�%d�����ڵ���Ŀ\n", i + 1);
        scanf(" %d", &(graph->AllNode[i].LinJinNum));
        Vnode *temp = malloc(sizeof (Vnode));
        graph->List[i].ptrVnode = (Vnode *) malloc(sizeof(Vnode));
        temp = graph->List[i].ptrVnode;                           //ʹtempָ��ÿ�������һ��Ԫ��
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

//�������
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
    int a[graph.NodeNum + 1];       //0������
    for (int i = 0; i <= graph.NodeNum ; ++i) {
        a[i] = 0;
    }
    BuildGraph(&graph);
    printf("DFS:\n");
    DFS(graph,1,a);
    for (int i = 0; i <= graph.NodeNum ; ++i) {
        a[i] = 0;
    }
    printf("\nBFS��\n");
    BFS(graph,1,a);
}