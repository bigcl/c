#include <stdio.h>
#include <stdarg.h>
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define MAXSIZE 200
typedef int  ElemType;

//����˳���
typedef struct{
    int i,j;
    ElemType e;
}Triple;


typedef struct {
    Triple data[MAXSIZE+1];//data[0]δ��
    int rpos[MAXSIZE];      //ÿ�е�һ��Ԫ��λ��
    int mu,nu,tu;    //����������������Ԫ����
}TSMatrix;

//������ת��Ϊ��Ԫ��
//���ｫ��ά���鵱��һά���鴫�룬�������a[0][0]�ĵ�ַ����ͨ����ַ�ֶ�Ѱ��
TSMatrix toTsMatrix(int *a,TSMatrix *matrix){
    matrix->tu = 1;
    matrix->data[0].i = matrix->mu;
    matrix->data[0].j = matrix->nu;
    for(int i = 1;i<=matrix->mu;i++){
        for (int j = 1; j <=matrix->nu; j++) {
            if((*(a+(i-1)*matrix->nu+j-1))){
                matrix->data[matrix->tu].i = i;
                matrix->data[matrix->tu].j = j;
                matrix->data[matrix->tu].e = *(a+(i-1)*matrix->nu+j-1) ;
                matrix->tu++;
            }
        }
    }
    matrix->tu--;
    matrix->data[0].e = matrix->tu;
}

void TtoA(TSMatrix T,int num[][MAXSIZE])//��Ԫ��ת��ά����
{
    for(int i=1;i<=T.tu;i++)
    {
        num[T.data[i].i][T.data[i].j] = T.data[i].e;
    }
}

void PrintSMatrix(TSMatrix M)
{
    int i,num[MAXSIZE][MAXSIZE]={0};
    TtoA(M, num);
    printf("����Ϊ��\n");
    for (int i = 1; i <= M.mu; i++)
    {
        for (int j = 1; j <= M.nu; j++)
        {
            printf("%4d", num[i][j]);
        }
        printf("\n");
    }
    printf("%d ��, %d �У� %d ������Ԫ�ء�\n", M.mu, M.nu, M.tu);
    printf("��Ԫ��Ϊ��\n");
    printf("%4s %4s %4s\n", "i", "j", "e");
    for (i = 1; i <= M.tu; i++)
        printf("%4d %4d %4d\n", M.data[i].i, M.data[i].j, M.data[i].e);

}
//��ȡ����Ԫ��˳�����λ��
void getRop(TSMatrix *matrix) {
    int nums[matrix->nu];
    //�Ȼ�ȡN��rps[i]
    for (int i = 1; i <= matrix->mu; i++) {
        nums[i] = 0;
        for (int j = 1; j <= matrix->tu; j++) {
            if (matrix->data[j].i == i) {
                nums[i]++;
                if (nums[i] == 1)                    //����Ԫ���к���Ҫ���rps��� ��Ϊ��һ��
                    matrix->rpos[i] = j;
            }
        }
        printf("��%d�еĵ�һ������Ԫλ��:%d\n", i, matrix->rpos[i]);
    }
}

int MatrixChen(TSMatrix matrix1,TSMatrix matrix2,TSMatrix *result){
    int ctemp[matrix2.nu+1],tp,p,q,cp,col,ccol,pcol;//��������ÿһ��Ԫ����˺͵Ľ��
    if(matrix1.tu*matrix2.tu == 0) return ERROR;
    result->mu = matrix1.mu;
    result->nu = matrix2.nu;
    result->tu = 0;
    for (int row = 1; row <= matrix1.mu;row++) {
        for(int j=1 ;j <= matrix2.nu;j++) {
            ctemp[j] = 0;         //���������
        }
        result->rpos[row] = result->tu + 1;         //��������Ա�ĵ�һ������Ԫ ���λ��
        if(row < matrix1.mu) tp = matrix1.rpos[row+1];  //����ÿһ�еı߽�ֵ(ԭ������밴�򴢴�)
        else tp = matrix1.tu + 1;
        for(p = matrix1.rpos[row];p < tp;p++){                  //��ʼ����ÿһ��
            col = matrix1.data[p].j;                            //�ҵ�Ҫ�������ֵ
            if(col < matrix2.mu) cp = matrix2.rpos[col + 1];
            else cp = matrix2.tu + 1;
            for(ccol = matrix2.rpos[col];ccol < cp;ccol++){
                pcol = matrix2.data[ccol].j;                //Ҫ��Ԫ�����ұ���к�
                ctemp[pcol] += matrix1.data[p].e * matrix2.data[ccol].e;        //�������Ԫ���ϳ˻�
            }
        }
        for(int column = 1; column <= matrix2.nu; ++column) {
            if(ctemp[column] != 0){
                result->tu++;
                result->data[result->tu].i = row;result->data[result->tu].j = column;result->data[result->tu].e = ctemp[column];
            }
        }
    }
    return OK;
}

void main(){
    int a[3][4]={{1,0,3,4},{1,3,0,0},{0,3,0,0}},b[4][2]={{1,0},{2,1},{3,5},{1,0}};
    TSMatrix matrix1,matrix2,result;
    matrix1.mu = 3;
    matrix1.nu = 4;
    matrix2.mu = 4;
    matrix2.nu = 2;
    toTsMatrix(*a,&matrix1);              //a�������a[0]�ĵ�ַ *a�������a[0][0]��ַ
    toTsMatrix(*b,&matrix2);
    getRop(&matrix1);
    getRop(&matrix2);
    PrintSMatrix(matrix1);
    PrintSMatrix(matrix2);
    MatrixChen(matrix1,matrix2,&result);
    PrintSMatrix(result);
}

