#define MAXSIZE 100
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
/* 
typedef struct Sqlist* List;
typedef struct
{
	int expn;
	int coef;
}duo;

typedef struct
{
	duo* elem;				//类似数组中的首地址 
	int length;				//当前长度 
}Sqlist; 
//初始化
List initlist()
{
	List P;
	P=(List)malloc(sizeof(Sqlist));			//动态一维数组
	 
	return P;								//返回地址 
}
int main()
{
	List P;
	P=initlist();
	P->length=3;
	printf("%d",P->length);
	return 0;
} */ 

//链表

typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;				//Node等价于结构体类型 PNode等价于结构体指针类型 

PNode creat_list();							//创建并初始化链表 
void travel_list(PNode pHead);				//遍历链表 
bool is_empty(PNode pHead);					//判断是否为空 
int ;				//求链表长度 
bool insert(PNode pHead,int pos,int val);	//在链表中插入某值 
bool delete_list(PNode pHead,int pos);		//删除某位置上的值 
void sort_list(PNode pHead);				//排序  
int main()
{
	PNode pHead=creat_list();				//创建并初始化链表 
	insert(pHead,2,1230);
	delete_list(pHead,1);
	sort_list(pHead);
	travel_list(pHead);						//遍历链表 
	printf("链表的长度为%d",length_list(pHead));
	return 0;
} 
//创建
/*
在循环之前构造"动态的"尾节点,在循环中不断更新,保证每次新增的节点为尾节点 
*/ 
PNode creat_list()
{
	int len;
	int val;
	int i;
	printf("请输入链表的长度:");
	scanf("%d",&len);
	if(len<=0)
	{
		printf("长度无效");
		exit(-1); 
	}
	PNode pHead=NULL;
	pHead=(PNode)malloc(sizeof(Node));
	pHead->pNext=NULL;
	PNode pTail=pHead;
	
	for(i=0;i<len;i++)
	{
		PNode pNew=(PNode)malloc(sizeof(Node));
		printf("请输入第%d个元素的值:",i+1);
		scanf("%d",&val);
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;		
	}
	return pHead;	
} 
//判断是否为空
bool is_empty(PNode pHead)
{
	if(pHead==NULL)	return true;
	else return false;
} 
//遍历数组 
/*
①对链表来说初始化相当于让p指向首节点
②对遍历链表来说截止相当于p==NULL 
即cnt=0;与p=pHead->pNext对应 
*/ 
void travel_list(PNode pHead)
{
	int i=0;
	//判断是否为空
	if(is_empty(pHead))
	{
		printf("数组为空"); 
	}
	PNode p=pHead->pNext;
	while(p!=NULL)
	{
		printf("第%d个元素的值为:%d\n",i+1,p->data);
		p=p->pNext;	
		i++;
	}				
	return; 
} 
//求链表的长度 
//注意cnt=0;与p=pHead->pNext对应  !! 
int length_list(PNode pHead)
{	
	int cnt=0;
	PNode p;
	p=pHead->pNext;
	while(p!=NULL)
	{
		cnt++;
		p=p->pNext;
	}
	return cnt;
}
//链表的pos前插入
/*
如何找到插入的位置前一个节点? 
cnt=0;与p=pHead->pNext对应后,从cnt=0循环到cnt=pos-1

*/ 
bool insert(PNode pHead,int pos,int val)
{
	int cnt,i=0;
	PNode t= pHead;
	PNode New=(PNode)malloc(sizeof(Node));
	while(t!=NULL&&i<pos-1)				 
	{	
		i++;
		t=t->pNext;
	}
	if(i>pos-1||pHead==NULL)
	{
		printf("插入失败"); 
		return false; 
	}
	New->data=val;
	New->pNext=t->pNext;
	t->pNext=New;
	printf("已将%d插入第%d个位置\n",val,pos);	
	return true;
}
//删除某位置上的值 
bool delete_list(PNode pHead,int pos)
{
	int cnt,i=0;
	PNode t= pHead;
	while(pHead!=NULL&&i<pos-1)
	{
		i++;
		t=t->pNext;
	}
	PNode p=t->pNext;
	t->pNext=t->pNext->pNext;
	free(p);	
} 

//排序(选择排序)
/*关键在于两个for循环内要进行翻译,把i=0翻译成p指向首节点
 把i++翻译成p=p->pNext
 翻译指在后面将翻译内容再写一遍 
*/ 
void sort_list(PNode pHead)
{
	int len=length_list(pHead);
	int i,j,t;
	PNode p;
	for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
	{
		for(j=i+1;j<len;j++)
		{
			if(p->data>p->pNext->data)
			{
				t=p->data;
				p->data=p->pNext->data;
				p->pNext->data=t;
			}
		}
	}
	return;
} 
