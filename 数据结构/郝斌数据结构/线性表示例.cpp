//����Ĳ���
//�ٴ��������â۵õ�Ԫ�ص�ֵ�ܲ��Ңݳ��Ȣ޲����ɾ��
#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
//ʾ������1(˳��洢�ṹ) 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
 
typedef struct SqList *List; //����һ���ṹ��ָ��List���� ָ��SqList���͵Ľṹ�� 
typedef struct SqList
{
    int Data[MAXSIZE];//��������  elementType��һ������  elementType Data[MAXSIZE];
    int Last; 			//���һ��Ԫ�ص�λ��(����) 
} L; 


List MakeEmpty() ///��ʼ�� �����ձ� 
{
    List list;
    list = (List)malloc(sizeof(L));
    list->Last=-1;
    return list; 
}

int Find(int X,List list)  //����list�е�ĳ��Ԫ�� X��λ�� 
{
    int i = 0;
    while(i<=list->Last && list->Data[i]!=X ) //С�����һ��Ԫ��λ�ã�����û�кͲ��ҵ�Ԫ����ȣ�������һ�� 
    {
        i++;
    }
    if(i > list->Last)
    {
        return -1 ; //I�Ѿ��������һ��Ԫ�ص�λ�ã�˵��û�ҵ�������-1 
    }
    else
    {
        return i ; //�ҵ���λ�� 
    } 
}
//����Ԫ�� 
void Insert(int X,int i,List list) //�ڵ�i��λ�ò��� 
{
    int j;
    if(list->Last==MAXSIZE-1) //������ 
    {
        printf("���Ѿ�����");
        return; 
    }
    if(i<1||i>list->Last+2) //����λ�ò���
    {
        printf("λ�ô���");
        return;
    }
    for(j=list->Last;j>=i-1;j--) //�ƶ��ڳ���λ 
    {
        list->Data[j+1] = list->Data[j];
    }
    list->Data[i-1] = X; //������Ԫ�� 
    list->Last++; //ָ���µ����һ��Ԫ��λ�� 
    return;
} 
//ɾ��Ԫ�� 
void Delete(int i, List list)
{
    int j;
    if(i<1||i>list->Last+1) //���λ�� 
    {
        printf("�����ڵ�%d��Ԫ��",i);
        return;
    }
    for(j=i;j<=list->Last;j++)
    {
        list->Data[j-1] = list->Data[j]; //��ǰ�ƶ�����λ 
    }
    list->Last--; //ָ���µ����һ��Ԫ��λ��
    return;
} 
List initlist()
{
	List P;
	P=(List)malloc(sizeof(L));			//��̬һά����
	return P;								//���ص�ַ 
}

int main()
{
    List list;
    list = initlist();
    int i,position;
    list->Last = 9;										//�������Ա���Ϊ9 
    for(i = 0;i<9;i++)
    {
        list->Data[i] = i+1 ;
    }
//    for(i=0;i<9;i++)
//    {
//        printf("��%d��������%d\n",i+1,list->Data[i+1]);
//    }
//ɾ������ 
  printf("��������Ҫɾ����λ��:");
	scanf("%d",&position);
	Delete(position,list);
//������� 
//	printf("��������Ҫ�����λ��:");
//	scanf("%d",&position);
//	Insert(22,position,list);
	for(i=0;i<=9;i++)
    {
        printf("��%d��������%d\n",i+1,list->Data[i]);
    }
	
} 

//ʾ��2
#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define list_init_size 80 //��ʼ����洢�ռ�
#define listincreament 10 //�洢�ռ��������
//�������Ա�Ľṹ
//typedef struct
//{
// int *elem; 		//�洢�ռ��ַ
// int length; 		//��ǰ����
// int listsize; 		//��ǰ����Ĵ洢����
//} SqList;
//
//
////����һ���յ����Ա���ʼ����
//int InitList_Sq(SqList *L)
//{
////��̬����һά����
//	L->elem=(int *)malloc(list_init_size*sizeof(int));
////�洢����ʧ��
//	if(!L->elem)
// 	exit(OVERFLOW);
////�ձ��ȳ�ʼ��Ϊ0��
//	L->length=0;
////�洢�ĳ�ʼ����Ϊ��ʼ����ռ�
//	L->listsize=list_init_size;
//	return OK;							//��ʼ���ɹ�����1						
//}
//
////���Ա�ĳ�ʼ������ 
//int Input_Sq(SqList *L,int n)			//nΪԪ�صĸ��� 
//{
//	int i, *newbase;
//	if(n<0)
//	{ 
// 		return ERROR;
// 	} 
//	if(n>L->listsize)					//���ڳ�ʼ�Ĵ洢����				
//	{
//		newbase=(int *)malloc(listincreament*sizeof(int));	//�������� 
//		if(!newbase)  exit(OVERFLOW);						//�Ƿ������ɹ� 
//		L->elem=newbase;									//									 
//		L->listsize+=listincreament;						//�洢������ 
//	}
//	printf("������Ԫ�أ�\n");
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&L->elem[i]);
//		L->length++;
//	}
//	return OK;
//}
//
//
//int ListInsert_Sq(SqList *L,int i,int e){
// 	//i��Ҫ����1<=i<=ListLength_Sq(L)+1
// int *newbase;
// int *p;
// int *q;
// if(i<1||i>L->length+1) return ERROR;
// if(L->length>=L->listsize){ //��ǰ�洢�ռ�����,���ӷ���
//newbase=(int *)realloc(L->elem,(L->listsize+listincreament)*sizeof(int));
//if(!newbase) exit(OVERFLOW); //�洢����ʧ��
//for(int j=0;j<L->length;j++)
//{
//newbase[j]=L->elem[j];
//}
//L->elem=newbase; //�»�ַ
//L->listsize+=listincreament;//���Ӵ洢����
// }
// q=&(L->elem[i-1]);//qΪ�����λ��(ע��������±��Ǵ�0��ʼ����)
// for(p=&(L->elem[L->length-1]);p>=q;p--)
//*(p+1)=*p; //����λ�ü�֮���Ԫ�غ���
// *q=e;//����e
// L->length+=1;//����1
// return L->length;
//}
//
//
//int Output_Sq(SqList *L, int i)
//{
// int j;
// printf("���º�����Ա�Ϊ��\n");
//for(j=0;j<i;j++)
//{
// printf("%d\t",L->elem[j]);
// }
// return OK;
//}
////��˳�����Ա�L��ɾ����i��Ԫ��,����e������ֵ
//
//
//int ListDelete_Sq(SqList *L,int i,int *e){
////i�ĺϷ���Ϊ1<=i<=ListLength_Sq(L)
//if(i<1||i>L->length) return ERROR;
//e=L->elem; //�ѱ�ɾ����Ԫ�ظ���e
//int *p=&L->elem[i-1]; //ָ��pΪ��ɾ��Ԫ�ص�λ��
//for(int *q=p+1;q<=p+(L->length-i);q++) *(q-1)=*q; //��ɾ��λ��֮���Ԫ�ض���ǰ��
//L->length-=1; //����һ?
//return OK;
//}
//int main()
//{
// SqList MYL;
// char a;
// a='Y';
// int k, data, position,*e;
// InitList_Sq(&MYL);
// printf("������Ԫ�صĸ���: ");
// scanf("%d",&k);
// Input_Sq(&MYL,k);
// while(a=='Y')
// {
// printf ("\n������Ҫ�����Ԫ�أ�");
// scanf("%d",&data);
// printf("\n������Ҫ�����λ�ã� ");
// scanf("%d",&position);
// ListInsert_Sq(&MYL,position,data);
// printf("&MYL.length");
// Output_Sq(&MYL,k+1);
// printf("\n������Ҫɾ����Ԫ�ص�λ�ã� ");
// scanf("%d",&position);
// ListDelete_Sq(&MYL,position,e);
// Output_Sq(&MYL,k);
// printf("\n�����Ƿ����?(Y:���� N:����)\n");
// getchar();
// scanf("%c",&a);
// }
// system("pause");
// return OK;
//}

//ʾ��3
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXSIZE 100
//
//typedef int ElemType;
//
//typedef struct{
//    ElemType data[MAXSIZE];
//    int length;
//}SqList;
//
//SqList *InitList(SqList *L);//��ʼ��
//void DestroyList(SqList *L);//����
//void ClearList(SqList *L);//����б�
//int ListEmpty(SqList *L);//�п�
//int ListLength(SqList *L);//�������Ա���
//int GetElem(SqList *L, int i, ElemType *e);//��ȡ��i��Ԫ��
//int LocateElem(SqList *L, ElemType e);//��λֵΪe��λ��
//ElemType PriorElem(SqList *L, ElemType cur_e);//����ǰ��
//ElemType NextElem(SqList *L, ElemType cur_e);//���Һ��
//int ListInsert(SqList *L, int i, ElemType e);//����Ԫ��
//int ListDelete(SqList *L, int i);//ɾ����i��Ԫ��
//int TraverseList(SqList *L);//�������Ա�
//
////��ʼ�����Ա�,����ͷָ��
//SqList* InitList(SqList *L){
//    int x;
//    int index = 0;
//
//    L = (SqList *)malloc(sizeof(SqList));
//    if(L){
//        printf("���뵽-1����\n");
//        while(1){
//            scanf("%d", &x);
//            if(x == -1){
//                printf("��ʼ���ɹ�\n");
//                break;
//            };
//            L->data[index++] = x;
//        }
//        L->length = index;
//    }else{
//        printf("�ռ䲻��,��ʼ��ʧ��\n");
//    }
//    return L;
//}
//
////�������Ա�
//void DestroyList(SqList *L){
//    free(L);
//    printf("���ٳɹ�\n");
//}
//
////������Ա�
//void ClearList(SqList *L){
//    int len = L->length;
//    int i;
//    for(i=0; i<len; i++){
//        L->data[i] = 0;
//    }
//    printf("��ճɹ�\n");
//}
//
////�пգ�1Ϊ��,0��Ϊ��
//int ListEmpty(SqList *L){
//    return (L->length == 0);
//}
//
////�������Ա���
//int ListLength(SqList *L){
//    return L->length;
//}
//
////��ȡ��i��Ԫ�أ������Ƿ��ȡ��״̬
//int GetElem(SqList *L, int i, ElemType *e){
//    if(i<1 || i>L->length){
//        printf("�����±�%dԽ��\n",i);
//        return 0;
//    }
//    *e = L->data[i-1];
//    printf("��%d��Ԫ����%d\n", i, *e);
//    return 1;
//}
//
////���ص�һ����e��ͬԪ�ص�λ�ã�������Ѱ�����±�
//int LocateElem(SqList *L, ElemType e){
//    int i;
//    for(i=0; i<L->length; i++){
//        if(L->data[i] == e){
//            printf("Ԫ��%d��λ���ǵ�%d��\n",e,i+1);
//            return i+1;
//        }
//
//    }
//    printf("%d, ���޴�Ԫ�ص��±�\n", e);
//    return 0;
//}
////����Ԫ��Ϊe��ǰ��Ԫ��
//ElemType PriorElem(SqList *L, ElemType cur_e){
//    int idx = LocateElem(L, cur_e);
//    ElemType e;
//    if(!idx){
//        return 0;
//    }
//    if(idx == 1){
//        printf("��һ��Ԫ��%dû��ǰ��\n", cur_e);
//        return 0;
//    }
//    GetElem(L, idx-1, &e);
//    printf("%dԪ�ص�ǰ����%d\n",cur_e, e);
//    return e;
//}
////����Ԫ��e�ĺ��Ԫ��
//ElemType NextElem(SqList *L, ElemType cur_e){
//    int idx = LocateElem(L, cur_e);
//    ElemType e;
//    if(!idx){
//        return 0;
//    }
//    if(idx == L->length){
//        printf("���һ��Ԫ��%dû�к��\n", cur_e);
//        return 0;
//    }
//    GetElem(L, idx+1, &e);
//    printf("%dԪ�صĺ����%d\n",cur_e, e);
//    return e;
//}
////���룬�����Ƿ����ɹ���״̬
//int ListInsert(SqList *L, int i, ElemType e){
//    if(i<1 || i>L->length+1){
//        printf("����λ������\n");
//        return 0;
//    }
//    if(L->length == MAXSIZE){
//        printf("���Ա������޷�������Ԫ��\n");
//        return 0;
//    }
//    int j;
//    for(j=L->length-1; j>=i-1; j--){
//        L->data[j+1] = L->data[j];
//    }
//    L->data[i-1] = e;
//    L->length++;
//    printf("����ɹ�\n");
//    return 1;
//}
////ɾ����i��Ԫ�أ������Ƿ�ɾ���ɹ���״̬
//int ListDelete(SqList *L, int i){
//    if(i<1 || i>L->length){
//        printf("ɾ��λ������\n");
//        return 0;
//    }
//    int j;
//    for(j=i; j<L->length; j++){
//        L->data[j-1] = L->data[j];
//    }
//    L->length--;
//    printf("ɾ���ɹ�\n");
//    return 1;
//}
//
////�������Ա�
//int TraverseList(SqList *L){
//    if(L->length == 0){
//        printf("�ձ�\n");
//        return 0;
//    }
//    if(L->length>MAXSIZE || L->length<-MAXSIZE){
//        printf("���Ա��ѱ��ݻٻ�δ��ʼ��\n");
//        return 0;
//    }
//    int j;
//    for(j=0; j<L->length; j++){
//        printf("%d ", L->data[j]);
//    }
//    printf("\n");
//}
//
//int main(void){
//    int idx;
//    int len;
//    ElemType e;
//    ElemType cur_e;
//    SqList *L = NULL;
//
//    L = InitList(L);

//    printf("���Ա���Ϊ%d\n",ListLength(L));

//    //�пղ���
//    if(ListEmpty(L))
//        printf("���Ա��\n");
//    else
//        printf("���Ա�Ϊ��\n");

//    //��ȡԪ�ز���
//    idx = 2;
//    GetElem(L, idx, &e);
//    GetElem(L, L->length+1, &e);

//    //��ȡλ�ò���
//    LocateElem(L, 3);

//    //��ȡǰ������
//    cur_e = 4;
//    PriorElem(L, cur_e);
//    GetElem(L, 1, &cur_e);
//    PriorElem(L, cur_e);

//    //�������
//    ListInsert(L, 1, 999);
//    TraverseList(L);
//    ListInsert(L, L->length+1, 999);
//    TraverseList(L);

//    //ɾ������
//    ListDelete(L, 1);
//    TraverseList(L);

//    //��ղ���
//    ClearList(L);
//    TraverseList(L);

//    //�ݻٲ���
//    DestroyList(L);
//    TraverseList(L);
//    return 0;
//} 

