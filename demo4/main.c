#include <stdio.h>
#include <stdarg.h>
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define MAXSIZE 200
typedef int  ElemType;

//定义顺序表
typedef struct{
    int i,j;
    ElemType e;
}Triple;


typedef struct {
    Triple data[MAXSIZE+1];//data[0]未用
    int rpos[MAXSIZE];      //每行第一个元素位置
    int mu,nu,tu;    //行数、列数、非零元个数
}TSMatrix;

//将数组转换为三元组
//这里将二维数组当作一维数组传入，传入的是a[0][0]的地址，再通过地址手动寻找
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

void TtoA(TSMatrix T,int num[][MAXSIZE])//三元组转二维数组
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
    printf("矩阵为：\n");
    for (int i = 1; i <= M.mu; i++)
    {
        for (int j = 1; j <= M.nu; j++)
        {
            printf("%4d", num[i][j]);
        }
        printf("\n");
    }
    printf("%d 行, %d 列， %d 个非零元素。\n", M.mu, M.nu, M.tu);
    printf("三元组为：\n");
    printf("%4s %4s %4s\n", "i", "j", "e");
    for (i = 1; i <= M.tu; i++)
        printf("%4d %4d %4d\n", M.data[i].i, M.data[i].j, M.data[i].e);

}
//获取非零元在顺序表中位置
void getRop(TSMatrix *matrix) {
    int nums[matrix->nu];
    //先获取N的rps[i]
    for (int i = 1; i <= matrix->mu; i++) {
        nums[i] = 0;
        for (int j = 1; j <= matrix->tu; j++) {
            if (matrix->data[j].i == i) {
                nums[i]++;
                if (nums[i] == 1)                    //非零元的行号与要求的rps相等 且为第一个
                    matrix->rpos[i] = j;
            }
        }
        printf("第%d行的第一个非零元位置:%d\n", i, matrix->rpos[i]);
    }
}

int MatrixChen(TSMatrix matrix1,TSMatrix matrix2,TSMatrix *result){
    int ctemp[matrix2.nu+1],tp,p,q,cp,col,ccol,pcol;//用来储存每一行元素相乘和的结果
    if(matrix1.tu*matrix2.tu == 0) return ERROR;
    result->mu = matrix1.mu;
    result->nu = matrix2.nu;
    result->tu = 0;
    for (int row = 1; row <= matrix1.mu;row++) {
        for(int j=1 ;j <= matrix2.nu;j++) {
            ctemp[j] = 0;         //先清空置零
        }
        result->rpos[row] = result->tu + 1;         //结果的线性表的第一个非零元 存放位置
        if(row < matrix1.mu) tp = matrix1.rpos[row+1];  //设置每一行的边界值(原本表必须按序储存)
        else tp = matrix1.tu + 1;
        for(p = matrix1.rpos[row];p < tp;p++){                  //开始计算每一行
            col = matrix1.data[p].j;                            //找到要计算的列值
            if(col < matrix2.mu) cp = matrix2.rpos[col + 1];
            else cp = matrix2.tu + 1;
            for(ccol = matrix2.rpos[col];ccol < cp;ccol++){
                pcol = matrix2.data[ccol].j;                //要乘元素在右表的列号
                ctemp[pcol] += matrix1.data[p].e * matrix2.data[ccol].e;        //计算非零元列上乘积
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
    toTsMatrix(*a,&matrix1);              //a传入的是a[0]的地址 *a传入的是a[0][0]地址
    toTsMatrix(*b,&matrix2);
    getRop(&matrix1);
    getRop(&matrix2);
    PrintSMatrix(matrix1);
    PrintSMatrix(matrix2);
    MatrixChen(matrix1,matrix2,&result);
    PrintSMatrix(result);
}

