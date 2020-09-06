//链表的操作
//①创建②重置③得到元素的值④查找⑤长度⑥插入和删除
#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
//示例代码1(顺序存储结构) 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
 
typedef struct SqList *List; //创建一个结构体指针List类型 指向SqList类型的结构体 
typedef struct SqList
{
    int Data[MAXSIZE];//建立数组  elementType是一个类型  elementType Data[MAXSIZE];
    int Last; 			//最后一个元素的位置(长度) 
} L; 


List MakeEmpty() ///初始化 建立空表 
{
    List list;
    list = (List)malloc(sizeof(L));
    list->Last=-1;
    return list; 
}

int Find(int X,List list)  //查找list中的某个元素 X的位置 
{
    int i = 0;
    while(i<=list->Last && list->Data[i]!=X ) //小于最后一个元素位置，并且没有和查找的元素相等，查找下一个 
    {
        i++;
    }
    if(i > list->Last)
    {
        return -1 ; //I已经大于最后一个元素的位置，说明没找到，返回-1 
    }
    else
    {
        return i ; //找到的位置 
    } 
}
//插入元素 
void Insert(int X,int i,List list) //在第i个位置插入 
{
    int j;
    if(list->Last==MAXSIZE-1) //表满了 
    {
        printf("表已经满了");
        return; 
    }
    if(i<1||i>list->Last+2) //插入位置不对
    {
        printf("位置错误");
        return;
    }
    for(j=list->Last;j>=i-1;j--) //移动腾出空位 
    {
        list->Data[j+1] = list->Data[j];
    }
    list->Data[i-1] = X; //插入新元素 
    list->Last++; //指向新的最后一个元素位置 
    return;
} 
//删除元素 
void Delete(int i, List list)
{
    int j;
    if(i<1||i>list->Last+1) //检查位置 
    {
        printf("不存在第%d个元素",i);
        return;
    }
    for(j=i;j<=list->Last;j++)
    {
        list->Data[j-1] = list->Data[j]; //向前移动补空位 
    }
    list->Last--; //指向新的最后一个元素位置
    return;
} 
List initlist()
{
	List P;
	P=(List)malloc(sizeof(L));			//动态一维数组
	return P;								//返回地址 
}

int main()
{
    List list;
    list = initlist();
    int i,position;
    list->Last = 9;										//定义线性表长度为9 
    for(i = 0;i<9;i++)
    {
        list->Data[i] = i+1 ;
    }
//    for(i=0;i<9;i++)
//    {
//        printf("第%d个数字是%d\n",i+1,list->Data[i+1]);
//    }
//删除操作 
  printf("请输入需要删除的位置:");
	scanf("%d",&position);
	Delete(position,list);
//插入操作 
//	printf("请输入需要插入的位置:");
//	scanf("%d",&position);
//	Insert(22,position,list);
	for(i=0;i<=9;i++)
    {
        printf("第%d个数字是%d\n",i+1,list->Data[i]);
    }
	
} 

//示例2
#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define list_init_size 80 //初始分配存储空间
#define listincreament 10 //存储空间分配增量
//定义线性表的结构
//typedef struct
//{
// int *elem; 		//存储空间基址
// int length; 		//当前长度
// int listsize; 		//当前分配的存储容量
//} SqList;
//
//
////构造一个空的线性表（初始化）
//int InitList_Sq(SqList *L)
//{
////动态开辟一维数组
//	L->elem=(int *)malloc(list_init_size*sizeof(int));
////存储分配失败
//	if(!L->elem)
// 	exit(OVERFLOW);
////空表长度初始化为0；
//	L->length=0;
////存储的初始容量为初始分配空间
//	L->listsize=list_init_size;
//	return OK;							//初始化成功返回1						
//}
//
////线性表的初始化输入 
//int Input_Sq(SqList *L,int n)			//n为元素的个数 
//{
//	int i, *newbase;
//	if(n<0)
//	{ 
// 		return ERROR;
// 	} 
//	if(n>L->listsize)					//大于初始的存储容量				
//	{
//		newbase=(int *)malloc(listincreament*sizeof(int));	//新增容量 
//		if(!newbase)  exit(OVERFLOW);						//是否新增成功 
//		L->elem=newbase;									//									 
//		L->listsize+=listincreament;						//存储量增加 
//	}
//	printf("情输入元素：\n");
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
// 	//i需要满足1<=i<=ListLength_Sq(L)+1
// int *newbase;
// int *p;
// int *q;
// if(i<1||i>L->length+1) return ERROR;
// if(L->length>=L->listsize){ //当前存储空间已满,增加分配
//newbase=(int *)realloc(L->elem,(L->listsize+listincreament)*sizeof(int));
//if(!newbase) exit(OVERFLOW); //存储分配失败
//for(int j=0;j<L->length;j++)
//{
//newbase[j]=L->elem[j];
//}
//L->elem=newbase; //新基址
//L->listsize+=listincreament;//增加存储容量
// }
// q=&(L->elem[i-1]);//q为插入的位置(注意数组的下标是从0开始计数)
// for(p=&(L->elem[L->length-1]);p>=q;p--)
//*(p+1)=*p; //插入位置及之后的元素后移
// *q=e;//插入e
// L->length+=1;//表长增1
// return L->length;
//}
//
//
//int Output_Sq(SqList *L, int i)
//{
// int j;
// printf("更新后的线性表为：\n");
//for(j=0;j<i;j++)
//{
// printf("%d\t",L->elem[j]);
// }
// return OK;
//}
////在顺序线性表L中删除第i个元素,并用e返回其值
//
//
//int ListDelete_Sq(SqList *L,int i,int *e){
////i的合法性为1<=i<=ListLength_Sq(L)
//if(i<1||i>L->length) return ERROR;
//e=L->elem; //把被删除的元素赋给e
//int *p=&L->elem[i-1]; //指针p为被删除元素的位置
//for(int *q=p+1;q<=p+(L->length-i);q++) *(q-1)=*q; //被删除位置之后的元素都往前移
//L->length-=1; //表长减一?
//return OK;
//}
//int main()
//{
// SqList MYL;
// char a;
// a='Y';
// int k, data, position,*e;
// InitList_Sq(&MYL);
// printf("请输入元素的个数: ");
// scanf("%d",&k);
// Input_Sq(&MYL,k);
// while(a=='Y')
// {
// printf ("\n请输入要插入的元素：");
// scanf("%d",&data);
// printf("\n请输入要插入的位置： ");
// scanf("%d",&position);
// ListInsert_Sq(&MYL,position,data);
// printf("&MYL.length");
// Output_Sq(&MYL,k+1);
// printf("\n请输入要删除的元素的位置： ");
// scanf("%d",&position);
// ListDelete_Sq(&MYL,position,e);
// Output_Sq(&MYL,k);
// printf("\n请问是否继续?(Y:继续 N:结束)\n");
// getchar();
// scanf("%c",&a);
// }
// system("pause");
// return OK;
//}

//示例3
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
//SqList *InitList(SqList *L);//初始化
//void DestroyList(SqList *L);//销毁
//void ClearList(SqList *L);//清空列表
//int ListEmpty(SqList *L);//判空
//int ListLength(SqList *L);//返回线性表长度
//int GetElem(SqList *L, int i, ElemType *e);//获取第i个元素
//int LocateElem(SqList *L, ElemType e);//定位值为e的位置
//ElemType PriorElem(SqList *L, ElemType cur_e);//查找前驱
//ElemType NextElem(SqList *L, ElemType cur_e);//查找后继
//int ListInsert(SqList *L, int i, ElemType e);//插入元素
//int ListDelete(SqList *L, int i);//删除第i个元素
//int TraverseList(SqList *L);//遍历线性表
//
////初始化线性表,返回头指针
//SqList* InitList(SqList *L){
//    int x;
//    int index = 0;
//
//    L = (SqList *)malloc(sizeof(SqList));
//    if(L){
//        printf("输入到-1结束\n");
//        while(1){
//            scanf("%d", &x);
//            if(x == -1){
//                printf("初始化成功\n");
//                break;
//            };
//            L->data[index++] = x;
//        }
//        L->length = index;
//    }else{
//        printf("空间不足,初始化失败\n");
//    }
//    return L;
//}
//
////销毁线性表
//void DestroyList(SqList *L){
//    free(L);
//    printf("销毁成功\n");
//}
//
////清空线性表
//void ClearList(SqList *L){
//    int len = L->length;
//    int i;
//    for(i=0; i<len; i++){
//        L->data[i] = 0;
//    }
//    printf("清空成功\n");
//}
//
////判空，1为空,0不为空
//int ListEmpty(SqList *L){
//    return (L->length == 0);
//}
//
////返回线性表长度
//int ListLength(SqList *L){
//    return L->length;
//}
//
////获取第i个元素，返回是否获取的状态
//int GetElem(SqList *L, int i, ElemType *e){
//    if(i<1 || i>L->length){
//        printf("查找下标%d越界\n",i);
//        return 0;
//    }
//    *e = L->data[i-1];
//    printf("第%d个元素是%d\n", i, *e);
//    return 1;
//}
//
////返回第一个与e相同元素的位置，返回找寻到的下标
//int LocateElem(SqList *L, ElemType e){
//    int i;
//    for(i=0; i<L->length; i++){
//        if(L->data[i] == e){
//            printf("元素%d的位置是第%d个\n",e,i+1);
//            return i+1;
//        }
//
//    }
//    printf("%d, 查无此元素的下标\n", e);
//    return 0;
//}
////返回元素为e的前驱元素
//ElemType PriorElem(SqList *L, ElemType cur_e){
//    int idx = LocateElem(L, cur_e);
//    ElemType e;
//    if(!idx){
//        return 0;
//    }
//    if(idx == 1){
//        printf("第一个元素%d没有前驱\n", cur_e);
//        return 0;
//    }
//    GetElem(L, idx-1, &e);
//    printf("%d元素的前驱是%d\n",cur_e, e);
//    return e;
//}
////返回元素e的后继元素
//ElemType NextElem(SqList *L, ElemType cur_e){
//    int idx = LocateElem(L, cur_e);
//    ElemType e;
//    if(!idx){
//        return 0;
//    }
//    if(idx == L->length){
//        printf("最后一个元素%d没有后继\n", cur_e);
//        return 0;
//    }
//    GetElem(L, idx+1, &e);
//    printf("%d元素的后继是%d\n",cur_e, e);
//    return e;
//}
////插入，返回是否插入成功的状态
//int ListInsert(SqList *L, int i, ElemType e){
//    if(i<1 || i>L->length+1){
//        printf("插入位置有误\n");
//        return 0;
//    }
//    if(L->length == MAXSIZE){
//        printf("线性表已满无法插入新元素\n");
//        return 0;
//    }
//    int j;
//    for(j=L->length-1; j>=i-1; j--){
//        L->data[j+1] = L->data[j];
//    }
//    L->data[i-1] = e;
//    L->length++;
//    printf("插入成功\n");
//    return 1;
//}
////删除第i个元素，返回是否删除成功的状态
//int ListDelete(SqList *L, int i){
//    if(i<1 || i>L->length){
//        printf("删除位置有误\n");
//        return 0;
//    }
//    int j;
//    for(j=i; j<L->length; j++){
//        L->data[j-1] = L->data[j];
//    }
//    L->length--;
//    printf("删除成功\n");
//    return 1;
//}
//
////遍历线性表
//int TraverseList(SqList *L){
//    if(L->length == 0){
//        printf("空表\n");
//        return 0;
//    }
//    if(L->length>MAXSIZE || L->length<-MAXSIZE){
//        printf("线性表已被摧毁或未初始化\n");
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

//    printf("线性表长度为%d\n",ListLength(L));

//    //判空测试
//    if(ListEmpty(L))
//        printf("线性表空\n");
//    else
//        printf("线性表不为空\n");

//    //获取元素测试
//    idx = 2;
//    GetElem(L, idx, &e);
//    GetElem(L, L->length+1, &e);

//    //获取位置测试
//    LocateElem(L, 3);

//    //获取前驱测试
//    cur_e = 4;
//    PriorElem(L, cur_e);
//    GetElem(L, 1, &cur_e);
//    PriorElem(L, cur_e);

//    //插入测试
//    ListInsert(L, 1, 999);
//    TraverseList(L);
//    ListInsert(L, L->length+1, 999);
//    TraverseList(L);

//    //删除测试
//    ListDelete(L, 1);
//    TraverseList(L);

//    //清空测试
//    ClearList(L);
//    TraverseList(L);

//    //摧毁测试
//    DestroyList(L);
//    TraverseList(L);
//    return 0;
//} 

