#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//创建一个带头结点的链表
Status createEmptyList(LinkList *L){//L为头指针 指向头节点
    *L = (LinkList)malloc(sizeof(LNode));   //为头节点分配内存空间
    if(!(*L)) exit(ERROR);
    (*L)->next = NULL;                      //令头节点的指向为空
}
//获取链表第i个元素
ElemType GetElem(LinkList linklist,int i){              //linklist是链表的头指针
    ElemType elemType;
    LNode *p;                                             //指定一个指针指向链表
    p = linklist->next;                               //p指向首元素节点
    int j = 1;                                        //j表示现在指向的第几个元素
    while(p && j<i){
        p = p->next;
        j++;            //p->第二个节点 j = 2
    }
    if(!p || j>i+1) return ERROR;
    elemType = p->data;
    return elemType;
}
//在第i个元素前插入el元素
Status Insert(LinkList linklist,int i,ElemType *el){ //linklist是链表的结点
    LNode *p;
    p = linklist->next;
    int j = 1;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    LinkList newNode = (LinkList)malloc(sizeof(LNode));     //创建一个指针指向新节点
    newNode->data = *el;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}
//获取链表长度
Status getListLengh(LinkList linklist){
    LNode *p;
    p = linklist->next;
    if(!p){
        return 0;
    }
    int j = 1;
    while(p != NULL){
        p = p->next;
        j++;
    }
    return j-1;
}
//倒序输出链表
void outPutList(LinkList linklist){
    int lengh = getListLengh(linklist);
    int i = lengh;
    ElemType el;
    while(i>0){
        el = GetElem(linklist,i);
        printf("%c",el);
        i--;
    }
}
//删除第i个节点
ElemType deleteElem(LinkList linklist,int i){
    LNode *p;
    LNode *deleteEl;
    ElemType elemType;
    p = linklist->next;
    int j = 1;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if(!p || j>i-1) return ERROR;
    deleteEl = p->next;
    elemType = deleteEl->data;
    p->next = deleteEl->next;
    free(deleteEl);
    return elemType;
}
void main(){
    LinkList L = NULL;
    LNode firstNode,secondNode,thirdNode;                      //L为头指针 指向头节点
    ElemType getElem,deleteElement;
    createEmptyList(&L);
    L->next = &firstNode;
    firstNode.data = 'A';
    secondNode.data = 'B';
    thirdNode.data = 'C';
    firstNode.next = &secondNode;
    secondNode.next = &thirdNode;
    thirdNode.next = NULL;
    outPutList(L);
    getElem = GetElem(L,3);
    printf("\n获取第三个元素:%c",getElem);
    Insert(L,2,&getElem);
    printf("\n插入后的链表反向输出结果:");
    outPutList(L);
    deleteElement = deleteElem(L,2);
    printf("\n删除的元素:%c",deleteElement);
    printf("\n删除过后的链表:");
    outPutList(L);
    printf("\n删除后的表长:%d", getListLengh(L));
}