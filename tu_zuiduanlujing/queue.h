//
// Created by joker on 2022/5/1.
//

#ifndef TU_ZUIDUANLUJING_QUEUE_H
#define TU_ZUIDUANLUJING_QUEUE_H

//
// Created by joker on 2022/4/24.
//
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR -1 //ElementType������ֵ����־����

typedef struct Node {
    ElementType data;
    struct Node* next;
}QNode;

typedef struct {
    QNode* front; //ָ���ͷ�ڵ�
    QNode* rear; //ָ���β�ڵ�
}Queue;

Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("�ռ䲻�㣡\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void AddQ(Queue* q, ElementType item) {
    QNode* qNode = (QNode*)malloc(sizeof(QNode));
    if (!qNode) {
        printf("�ռ䲻�㣡\n");
        return;
    }
    qNode->data = item;
    qNode->next = NULL;
    if (q->front == NULL) {
        q->front = qNode;
    }
    if (q->rear == NULL) {
        q->rear = qNode;
    }
    else {
        q->rear->next = qNode;
        q->rear = qNode;
    }
}

int IsEmptyQ(Queue* q){
    return (q->front == NULL);
}

ElementType DeleteQ(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("�ն���\n");
        return ERROR;
    }
    QNode* temp = q->front;
    ElementType item;
    if (q->front == q->rear) { //������ֻ��һ��Ԫ��
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    item = temp->data;
    free(temp);
    return item;
}

void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("�ն���\n");
        return;
    }
    printf("��ӡ��������Ԫ�أ�\n");
    QNode* qNode = q->front;
    while (qNode != NULL) {
        printf("%d " , qNode->data);
        qNode = qNode->next;
    }
    printf("\n");
}

#endif //TU_ZUIDUANLUJING_QUEUE_H
