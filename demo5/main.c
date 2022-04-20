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

/*
 * 插入搜索树
 * biTree->leftchild = Insert(e,biTree->leftchild);   是为了将树连接在一起 如果不是插入位置即不是叶子结点 则树的左右子树还按照原来连接 否则就是做插入操作了
 */
BiTree Insert(ElementType e,BiTree biTree){
    //若为根节点 则分配内存 准备做插入
    if(!biTree){
        biTree = (BiNode *) malloc(sizeof (BiNode));
        biTree->data = e;
        biTree->leftchild = biTree->rightchild = NULL;
    } else{
        if(e < biTree->data) biTree->leftchild = Insert(e,biTree->leftchild);           //如果比左边小        往左子树插
        if(e > biTree->data) biTree->rightchild = Insert(e,biTree->rightchild);          //如果比右边大        往右子树插
    }
    return biTree;
}

void OutputBiTree(BiTree biTree){
    if(biTree){
        printf("%d\t",biTree->data);
        OutputBiTree(biTree->leftchild);
        OutputBiTree(biTree->rightchild);
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
    printf("\n二叉树深度为：%d\n", GetBiTreeDeepth(biTree));
    Insert(29,biTree);
    OutputBiTree(biTree);
    printf("\n二叉树深度为：%d\n", GetBiTreeDeepth(biTree));
}
