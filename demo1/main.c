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
//����һ����ͷ��������
Status createEmptyList(LinkList *L){//LΪͷָ�� ָ��ͷ�ڵ�
    *L = (LinkList)malloc(sizeof(LNode));   //Ϊͷ�ڵ�����ڴ�ռ�
    if(!(*L)) exit(ERROR);
    (*L)->next = NULL;                      //��ͷ�ڵ��ָ��Ϊ��
}
//��ȡ�����i��Ԫ��
ElemType GetElem(LinkList linklist,int i){              //linklist�������ͷָ��
    ElemType elemType;
    LNode *p;                                             //ָ��һ��ָ��ָ������
    p = linklist->next;                               //pָ����Ԫ�ؽڵ�
    int j = 1;                                        //j��ʾ����ָ��ĵڼ���Ԫ��
    while(p && j<i){
        p = p->next;
        j++;            //p->�ڶ����ڵ� j = 2
    }
    if(!p || j>i+1) return ERROR;
    elemType = p->data;
    return elemType;
}
//�ڵ�i��Ԫ��ǰ����elԪ��
Status Insert(LinkList linklist,int i,ElemType *el){ //linklist������Ľ��
    LNode *p;
    p = linklist->next;
    int j = 1;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    LinkList newNode = (LinkList)malloc(sizeof(LNode));     //����һ��ָ��ָ���½ڵ�
    newNode->data = *el;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}
//��ȡ������
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
//�����������
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
//ɾ����i���ڵ�
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
    LNode firstNode,secondNode,thirdNode;                      //LΪͷָ�� ָ��ͷ�ڵ�
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
    printf("\n��ȡ������Ԫ��:%c",getElem);
    Insert(L,2,&getElem);
    printf("\n������������������:");
    outPutList(L);
    deleteElement = deleteElem(L,2);
    printf("\nɾ����Ԫ��:%c",deleteElement);
    printf("\nɾ�����������:");
    outPutList(L);
    printf("\nɾ����ı�:%d", getListLengh(L));
}