#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Swap(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序（从小到大）
void MaoPaoPaiXu(int *array, int length){
    for(int i = length - 1;i >= 0 ;i--){
        int flag = 0;
        for(int j = 0; j < i; j++){
            if(array[j] > array[j+1]){
                Swap(&array[j],&array[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;                    //若从头到位都没有发生交换 则已经是有序的 退出排序
    }
}

//插入排序
void ChaRuPaiXu(int *array,int length){
    for(int N = 1;N < length;N++){      //从第二个开始插
        int Temp = array[N];            //记录要插的数值
        int Pre;
        for(Pre = N; Pre >= 0 && array[Pre-1] > Temp;Pre--){        //若要插的数值比前一张牌小，前一张牌后移，一直到合适的位置
            array[Pre] = array[Pre - 1];
        }
        array[Pre] = Temp;
    }
}


//希尔排序(增量序列不互质，确保之前的排序对最后增量序列为1时排序消除的逆序对)（错误代码）
void XiErPaiXu(int *array,int length){
    for(int D = length/5;D >= 1;D = D/2){       //每次循环都保证间隔为D是有序的 一直到间隔为1 为他消除较多的逆序列
        for(int N = D;N < length;N = N + D){
            int Temp = array[N];
            int Pre;
            for(Pre = N;Pre >= 0 && array[Pre-D] > Temp;Pre = Pre - D){
                array[Pre] = array[Pre - D];
            }
            array[Pre] = Temp;
        }
    }
}

//选择排序法 每次将未排序的最小值 插入到已排序的末尾
void XuanZePaiXu(int *array,int length){
    int minIndex;
    //遍历已排序的位置
    for(int i = 0;i < length;i++){
        int min = 9999;
        for(int j = i ;j < length; j++){
            if(array[j] < min) {
                min = array[j];
                minIndex = j;
            }
        }
        Swap(&array[i],&array[minIndex]);
    }
}

//找主元，采取寻找中位数的方法 并将左右边界按大小顺序排好，然后将主元放在right - 1的位置上，方便排序寻找
void FindPivot(int *array, int left, int right){
    int mid = (left + right) / 2;
    if(array[left] > array[right]){
        Swap(&array[left],&array[right]);
    }
    if(array[mid] > array[right]){
        Swap(&array[mid], &array[right]);
    }
    if(array[left] > array[mid]){
        Swap(&array[left], &array[mid]);
    }
    Swap(&array[mid],&array[right-1]);
}

//快速排序 选取主元将其一次性放在对的位置
void QuicklySort(int *array,int left, int right){
    FindPivot(array,left,right);
    if(left >= right - 2) return;                            //当要排序的仅为3个数时，在找主元的时候就已经把这三个数字排序，即可返回
    int i = left + 1,j = right - 2, pivot = array[right-1];         //设定左右指针开始位置
    while (1){
        while (array[i] < pivot){i++;}
        while (array[j] > pivot){j--;}                                //将i和j停在位置不对的元素上
        if(i < j){
            Swap(&array[i],&array[j]);                  //将位置不对的元素相互交换，使其位置正确
        } else break;
    }
    Swap(&array[right-1],&array[i]);     //将主元换到中间位置（一定要和i换，因为i此时指向的是比pivot大的数字，可以将其换到right-1即pivot右边的集合）
    QuicklySort(array,left,i-1);
    QuicklySort(array,i+1 ,right);
}


//堆排序
//将以p为根节点的子堆调整为最大堆
//前提条件是在进行操作之前，堆就是正确排列的
void PreDown(int *maxHeap, int p, int N){
    int temp = maxHeap[p];//将要下滤的节点保存
    int Parent = p,Child;
    //循环的条件就是判断其左孩子是否存在
    for(Parent = p;Parent * 2 + 1 <= N - 1 ;Parent = Child){
        Child = Parent * 2 + 1;
        //此处判断是否有右孩子，并且右孩子比左孩子要大
        if(Parent * 2 + 2 <= N - 1 && maxHeap[Parent * 2 + 1] < maxHeap[Parent * 2 + 2]){
            Child++;                        //从左右孩子里找最大的
        }
        if(maxHeap[Child] < temp) break;
        else{
            maxHeap[Parent] = maxHeap[Child];
        }
    }
    maxHeap[Parent] = temp;                         //此时Parent就是他要调整的位置
}


void BuildMaxHeap(int *maxHeap, int N){
    for(int i = (N - 1) / 2; i >= 0; i--){
        PreDown(maxHeap,i,N);
    }
}





void PrintArray(int *array,int length){
    for(int i = 0; i < length; i++){
        printf("%d   ",array[i]);
    }
}

int main(){
    int array[6];
    array[0] = 3;
    array[1] = 4;
    array[2] = 6;
    array[3] = 1;
    array[4] = 5;
    array[5] = 7;

    BuildMaxHeap(array,6);

    for( int i = 5; i >=0 ;i--){
        Swap(&array[i],&array[0]);
        PreDown(array,0,i);
    }
    PrintArray(array,6);
}
