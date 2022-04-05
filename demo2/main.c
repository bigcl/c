#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef int SElemType;
typedef struct{
    SElemType *base;                    //栈底 （必须指定为栈中元素指针，否则 top++有问题）
    SElemType *top;                         //通常令top = base + stacksize 方便进站出站
    int stacksize;                  //栈的已分配空间大小
}Stack;

Status InitStack(Stack *stack){
    stack->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));                 //为栈分配空间
    if(!stack->base) return ERROR;
    stack->top = stack->base;     //令栈为空栈
    stack->stacksize = STACK_INIT_SIZE;
    return OK;
};

Status Push(Stack *stack,SElemType el){
    if(stack->top - stack->base >= stack->stacksize){                          //若栈满则给栈分配新增空间
        stack->base = (SElemType *) realloc(stack->base,(STACK_INIT_SIZE + STACKINCREMENT) * sizeof (SElemType));
        if(!stack->base) exit(ERROR);
        stack->top = stack->base + stack->stacksize;//将栈顶指向原先栈满位置
        stack->stacksize = stack->stacksize + STACKINCREMENT;
    }
    *(stack->top) = el;
    stack->top = stack->top +1;
    return OK;
}

SElemType Pop(Stack *stack){
    if(stack->top <= stack->base) return ERROR;
    SElemType el;
    stack->top = stack->top - 1;
    el = *(stack->top);
    return el;
}
int main() {
    int inputNum;
    scanf("%d",&inputNum);
    Stack stack;
    InitStack(&stack);
    while (inputNum){
        Push(&stack,inputNum % 8);             //使余数进栈
        inputNum = inputNum / 8;
    }
    while ((stack.top - stack.base)>0){
        printf("%d",Pop(&stack));
    }
}


