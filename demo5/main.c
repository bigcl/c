#include <stdio.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElementType;

typedef struct{
    ElementType data;
    struct BiNode *leftchild,*rightchild;
}BiNode,*BiTree;

//���򴴽�������
Status CreateBiTree(BiTree* biTree){
    ElementType el;
    scanf("%d",&el);
    if(el != 0) {            //�Ƿ�ΪҶ�ӽڵ�
        *biTree = (BiNode *) malloc(sizeof(BiNode));
        (*biTree)->data = el;
        CreateBiTree(&(*biTree)->leftchild);                //����������
        CreateBiTree(&(*biTree)->rightchild);               //����������
    }
    else{
        *biTree = NULL;
    }
}

void PreOutputBiTree(BiTree biTree){
    if(biTree){
        printf("%d\t",biTree->data);
        OutputBiTree(biTree->leftchild);
        OutputBiTree(biTree->rightchild);
    }
}

void InOutputBiTree(BiTree biTree)
{
    if (biTree)
    {
        OutputBiTree(biTree->leftchild);
        printf("%d\t", biTree->data);
        OutputBiTree(biTree->rightchild);
    }
}
void PosOutputBiTree(BiTree biTree)
{
    if (biTree)
    {
        OutputBiTree(biTree->leftchild);
        OutputBiTree(biTree->rightchild);
        printf("%d\t", biTree->data);
    }
}
//����������
int GetBiTreeDeepth(BiTree biTree){                                         //ʹ�õݹ� �Ƚ�ÿ������������������������� ���ÿ�����������
    int deepth = 0;
    if(biTree){
        deepth++;
        int left_deepth = GetBiTreeDeepth(biTree->leftchild);
        int right_deepth = GetBiTreeDeepth(biTree->rightchild);
        if(left_deepth >= right_deepth) deepth += left_deepth;
        else deepth  += right_deepth;
    }
    return deepth;
}

void main(){
    BiTree biTree;
    CreateBiTree(&biTree);
    OutputBiTree(biTree);
    printf("\n����������Ϊ��%d", GetBiTreeDeepth(biTree));
}
