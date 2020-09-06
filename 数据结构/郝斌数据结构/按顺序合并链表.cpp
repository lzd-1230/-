#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;
		
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

void MergeList(PNode &La,PNode &Lb, PNode &Lc)
{
	//双链表初始化为首节点 
	PNode pa=La->pNext;
	PNode pb=Lb->pNext;
	
	PNode t;
	PNode pc=La;					//pc会成为Lc最后的尾节点
	Lc=pc; 							//利用了La的头结点作为自己的头结点 
	//这样做的原理是pa和pb都是前一个,因此将pc->pNext修改不会影响到pa,pb的正常后移 
	while(pa && pb)					//当二者都不为空 
	{
		if(pa->data>pb->data)		//比较大小 
		//让pc的下一个直接指向pb的结点 
		{ 
			pc->pNext=pb;			//每次对pc->pNext进行操作可以使pc的结点有自己的想法 
			pc=pb;					//让pc始终指向链表的最末端
			pb=pb->pNext;
		}
		else if(pa->data<pb->data)
		{
			pc->pNext=pa;
			pc=pa;
			pa=pa->pNext;
		}
		else
		{
			pc->pNext=pa;
			pc=pa;
			pa=pa->pNext;
			
			t=pb->pNext;
			free(pb);			//free的意思是把pb指向的结点释放了,但pb仍存在,可以继续用其它地址赋值 
			pb=t;			
		}
	}
	while(pa || pb) 		//两个之中有非空的 
	{
		if(pa)
		{
			pc->pNext=pa;
			pc=pa;
			pa=pa->pNext;	
		}
		else
		{
			pc->pNext=pb;			//每次对pc->pNext进行操作可以使pc的结点有自己的想法 
			pc=pb;					//让pc始终指向链表的最末端
			pb=pb->pNext;
		}
	}
}
//递归写法
PNode MergeList1(PNode &La,PNode &Lb)
{
	if(!La)
		return Lb;
	else if(!Lb)
		return La;
		
	if(La->data<Lb->data)
	{
		La->pNext=MergeList1(La->pNext,Lb);
		return La;
	}
		
	if(La->data>=Lb->data)
	{
		Lb->pNext=MergeList1(La,Lb->pNext);
		return Lb;
	}
		
} 
int main()
{
	PNode La,Lb,Lc=NULL;
	La=creat_list();
	Lb=creat_list();
	MergeList1(La,Lb);
	travel_list(Lb); 
	return 0;
}
