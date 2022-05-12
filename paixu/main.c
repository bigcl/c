#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Swap(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//ð�����򣨴�С����
void MaoPaoPaiXu(int *array, int length){
    for(int i = length - 1;i >= 0 ;i--){
        int flag = 0;
        for(int j = 0; j < i; j++){
            if(array[j] > array[j+1]){
                Swap(&array[j],&array[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;                    //����ͷ��λ��û�з������� ���Ѿ�������� �˳�����
    }
}

//��������
void ChaRuPaiXu(int *array,int length){
    for(int N = 1;N < length;N++){      //�ӵڶ�����ʼ��
        int Temp = array[N];            //��¼Ҫ�����ֵ
        int Pre;
        for(Pre = N; Pre >= 0 && array[Pre-1] > Temp;Pre--){        //��Ҫ�����ֵ��ǰһ����С��ǰһ���ƺ��ƣ�һֱ�����ʵ�λ��
            array[Pre] = array[Pre - 1];
        }
        array[Pre] = Temp;
    }
}


//ϣ������(�������в����ʣ�ȷ��֮ǰ������������������Ϊ1ʱ���������������)
void XiErPaiXu(int *array,int length){
    for(int D = length/5;D >= 1;D = D/2){       //ÿ��ѭ������֤���ΪD������� һֱ�����Ϊ1 Ϊ�������϶��������
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

//ѡ������ ÿ�ν�δ�������Сֵ ���뵽�������ĩβ
void XuanZePaiXu(int *array,int length){
    int minIndex;
    //�����������λ��
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

//����Ԫ����ȡѰ����λ���ķ��� �������ұ߽簴��С˳���źã�Ȼ����Ԫ����right - 1��λ���ϣ���������Ѱ��
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

//�������� ѡȡ��Ԫ����һ���Է��ڶԵ�λ��
void QuicklySort(int *array,int left, int right){
    FindPivot(array,left,right);
    if(left >= right - 2) return;                            //��Ҫ����Ľ�Ϊ3����ʱ��������Ԫ��ʱ����Ѿ����������������򣬼��ɷ���
    int i = left + 1,j = right - 2, pivot = array[right-1];         //�趨����ָ�뿪ʼλ��
    while (1){
        while (array[i] < pivot){i++;}
        while (array[j] > pivot){j--;}                                //��i��jͣ��λ�ò��Ե�Ԫ����
        if(i < j){
            Swap(&array[i],&array[j]);                  //��λ�ò��Ե�Ԫ���໥������ʹ��λ����ȷ
        } else break;
    }
    Swap(&array[right-1],&array[i]);     //����Ԫ�����м�λ�ã�һ��Ҫ��i������Ϊi��ʱָ����Ǳ�pivot������֣����Խ��任��right-1��pivot�ұߵļ��ϣ�
    QuicklySort(array,left,i-1);
    QuicklySort(array,i+1 ,right);
}

void PrintArray(int *array,int length){
    for(int i = 0; i < length; i++){
        printf("%d   ",array[i]);
    }
}

int main(){
    int array[20];
    for(int i = 0;i < 20; i++){
        array[i] = rand()%501;      //���ɷ�Χ��500�������
    }
    printf("ð������\n");
    MaoPaoPaiXu(array,20);
    PrintArray(array,20);
    printf("\n��������\n");
    ChaRuPaiXu(array,20);
    PrintArray(array,20);
    printf("\nϣ������\n");
    XiErPaiXu(array,20);
    PrintArray(array,20);
    printf("\nѡ������\n");
    XuanZePaiXu(array,20);
    PrintArray(array,20);
    for(int i = 0;i < 20; i++){
        array[i] = rand()%501;      //���ɷ�Χ��500�������
    }
    printf("\n��������\n");
    QuicklySort(array,0,19);
    PrintArray(array,20);
}