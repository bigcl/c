#include <stdio.h>
int erfenchazhao(int num,int* arry,int length);
int main() {
    int arry[11] = {5,13,19,21,37,56,64,75,80,88,92};
    printf("21�ڣ�%d\n",erfenchazhao(21,arry,11));
    printf("85��: %d",erfenchazhao(85,arry,11));
}

int erfenchazhao(int num,int* arry,int length){
    int left = -1,right = length;                               //��ʼ�����������-1�ұ�length
    int mid = (left + right)/2;
    while(left <= right){
        if(num < arry[mid]){
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else if(num > arry[mid]){
            left = mid + 1;
            mid = (left + right) / 2;
        } else return mid + 1;
    }
    return 0;
}
