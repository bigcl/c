#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct {
    char *ch;
    int length;
}HString;

//���ڴ����Ӵ��ڸ�����λ�ü�����
typedef struct {
    int *index;
    int times;
}SonIndex;

//��ʼ���� ����Ȼ��Ҳ��֪��ΪʲôҪ����ַ�ȸ���ֵ����������ʲô�ѳ��������ָ���ַ��0*8��
void InitString(HString *str, int i, char string[13]) {
str->ch = NULL;
str->length = 0;
}

int getLength(char *string){
    int length = 0;
    for(;string[length];length++);
    return length;
}


//��str�ĵ�n��Ԫ��ǰ����string
Status InsertStr(HString *str,int position,char *string){
    int size = str->length + getLength(string);
    if(position < 1||position > str->length + getLength(string)) return ERROR;
    if(getLength(string)){
        str->ch = (char *) realloc(str->ch,size * sizeof(char));//Ϊ�ַ����������ڴ�ռ�
        if(!str->ch) return ERROR;
        for(int i = position - 1;i < str->length;i++){                   //������ط�����Ԫ�ػ�λ
            str->ch[i + getLength(string)] = str->ch[i];
        }
        for(int i = position -1,j = 0;(i <= position -1 + getLength(string)) && j <= getLength(string) ;i++,j++){
            str->ch[i] = string[j];
        }
        str->length += getLength(string);
    }
    return OK;
}


//����string��str�е�λ�úʹ���(�����ƽⷨ)
SonIndex IndexString(HString str,HString string){
    SonIndex sonIndex;
    int i=0,j=0,index[255],times=0,flag;
    for(i=0;i<=str.length - string.length;i++){
        flag = 1;
        for(j=0;j<string.length;j++){
            if(str.ch[i+j] != string.ch[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            index[times] = i;
            times++;
        }
    }
    sonIndex.index = index;
    sonIndex.times = times;
    return sonIndex;
}

void main() {
    HString str,indexString;
    InitString(&str, 0, NULL);
    InitString(&indexString, 0, NULL);
    indexString.ch = "life";
    indexString.length = getLength("life");
    char a[50],b[50];
    FILE *fp1 = fopen("D:/c_tools/c_projects/demo3/text1.txt","r");
    FILE *fp2 = fopen("D:/c_tools/c_projects/demo3/text2.txt","r");
    FILE *fp3 = fopen("D:/c_tools/c_projects/demo3/newfile.txt","w+");
    fgets(a,50,fp1);
    fgets(b,50,fp2);
    fclose(fp1);
    fclose(fp2);
    printf("�ϲ���Ĵ�:");
    InsertStr(&str,1,a);
    InsertStr(&str,str.length + 1,b);
    printf("%s\n",str.ch);
    printf("�������Ӵ�:%s",indexString.ch);
    SonIndex sonIndex = IndexString(str,indexString);
    printf("\n�Ӵ��ڸ������ֵĴ���:%d\n",sonIndex.times);
    printf("���ֵ�λ��:");
    for(int i=0;i<sonIndex.times;i++){
        printf("(%d,%d)",sonIndex.index[i]+1,sonIndex.index[i]+indexString.length);
    }
    fputs(str.ch,fp3);
    fclose(fp3);
}
