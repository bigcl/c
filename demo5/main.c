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

//先序创建二叉树
Status CreateBiTree(BiTree* biTree){
    ElementType el;
    scanf("%d",&el);
    if(el != 0) {            //是否为叶子节点
        *biTree = (BiNode *) malloc(sizeof(BiNode));
        (*biTree)->data = el;
        CreateBiTree(&(*biTree)->leftchild);                //创建左子树
        CreateBiTree(&(*biTree)->rightchild);               //创建右子树
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
//获得树的深度
int GetBiTreeDeepth(BiTree biTree){                                         //使用递归 比较每个子树的左子树和右子树深度 获得每个子树的深度
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
    printf("\n二叉树长度为：%d", GetBiTreeDeepth(biTree));
}
