#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;			//Node等价于结构体类型 PNode等价于结构体指针类型 

PNode creat_list();							//创建并初始化链表 
void travel_list(PNode pHead);				//遍历链表 
bool is_empty(PNode pHead);					//判断是否为空 
int length_list(PNode pHead);				//求链表长度 
bool insert(PNode pHead,int pos,int val);	//在链表中插入某值 
bool delete_list(PNode pHead,int pos);		//删除某位置上的值 
void sort_list(PNode pHead);				//排序 
int main()	
{
	PNode pHead=NULL;
	pHead=creat_list();		//创建一个链表
	if(is_empty(pHead))
		printf("链表为空\n");
	sort_list(pHead);
	insert(pHead,2,1230); 
	travel_list(pHead); 	//遍历链表 
	delete_list(pHead,2);
	travel_list(pHead);
	printf("链表的长度为%d\n",length_list(pHead));
	return 0;
}
//创建链表
PNode creat_list()
{
	int i;
	int len;			//用来存放有效节点的个数 
	int val;			//用来临时存放输入的数据域的值 
	printf("请输入链表的节点数:len=");
	scanf("%d",&len);
	
	PNode pHead=(PNode)malloc(sizeof(Node));	//定义一个头结点
	if(pHead==NULL)
	{
		printf("头结点分配失败,程序终止\n");
		exit(-1); 
	} 
	
	PNode pTail=pHead;								//初始化尾指针 
	pTail->pNext=NULL; 								//保证尾指针的指针域为空 
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值",i+1); 
		scanf("%d",&val);
		PNode pNew=(PNode)malloc(sizeof(Node));		//建立新节点存储数据 
			if(pNew==NULL)
			{
				printf("头结点分配失败,程序终止\n");
				exit(-1); 
			} 
		pNew->data=val;					//把输入的数据给到该节点数据域 
		pTail->pNext=pNew;				//让pNew挂到尾节点上面 
		pNew->pNext=NULL;				//把pNew指针域清空,变成新的尾节点 
		pTail=pNew; 					//每次的pNew对下一个节点来说都是尾节点 
	}
	return pHead;						//别忘记返回creat出来的pHead 
}
//遍历链表 
void travel_list(PNode pHead)
{
	PNode P=pHead->pNext;				//P中存放的是首节点的地址		
	while(P!=NULL)						//注意区分,不是P->pNext!=NULL 
	{
		printf("%d\n",P->data); 
		P=P->pNext;						//让P指向下一个节点 
	}
	return; 
}
bool is_empty(PNode pHead)
{
	if(pHead->pNext==NULL)
		return true;
	else 
		return false;
}
//求链表长度 
int length_list(PNode pHead)
{
	int cnt=0;
	PNode P=pHead->pNext;			//首节点开始 
	while(P!=NULL)
	{
		cnt++;
		P=P->pNext;
	}
	return cnt;
} 
//在链表排序 
void sort_list(PNode pHead)
{
	int len=length_list(pHead);
	PNode P,Q;
	P=pHead;
	int i,j,t;
	for(i=0,P=P->pNext;i<len-1;i++,P=P->pNext)		//除了中间的条件不动外,两边多一条翻译 
	{
		for(Q=P->pNext,j=i+1;j<len;j++,Q=Q->pNext)
		{
			if(Q->data>P->data)						//后面不能比前面大,固降序 
			{
				t=P->data;
				P->data=Q->data;
				Q->data=t;
			}
		}
	}
} 
//在链表中插入
bool insert(PNode pHead,int pos,int val)	//在pos前面插入val 
{
	if(pos>length_list(pHead))
	{
		printf("插入的位置无效\n");
		exit(-1);
	} 
	int i=0;
	PNode p=pHead;
	while(NULL!=p && i<pos-1)		//在pos前面插入  
	{
		i++;
		p=p->pNext;
	}
	if(i>pos-1||pHead==NULL)
	{
		printf("输入的位置或链表有误,插入失败"); 
		return false; 
	}
	
	PNode q=p->pNext;						//q是下一个节点 
	PNode tNew=(PNode)malloc(sizeof(Node));
	if(tNew==NULL)
	{
		printf("动态内存分配失败!\n");
		exit(-1); 
	} 
	tNew->pNext=q;
	p->pNext=tNew;
	tNew->data=val;
	return true; 
} 
//删除链表中某位置的元素
bool delete_list(PNode pHead,int pos)
{
	int i=0;
	PNode p=pHead;
	while(p!=NULL && i<pos-1)
	{
		i++;
		p=p->pNext;
	}
	PNode q=p->pNext;
	p->pNext=p->pNext->pNext;
	free(q);
} 
