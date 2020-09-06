#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//顺序存储结构(循环队列) 
/* 
int len =10;
typedef struct queque
{
	int * pbase;				//循环数组 
	int front;					//front 和 rear都相当于数组下标 
	int rear;					//rear指向的是下一个元素进来的位置,该位置没有元素!! 
}que;	

bool is_empty(que*); 
bool out_que(que* ,int *);
void travel(que* );
void init(que* pq);
bool input(que* pq,int val);
bool full_que(que* pq);

int main()
{
	int val;
	que q;
	init(&q);
	input(&q,1);
	input(&q,2);
	input(&q,3);
	input(&q,4);
	if(out_que(&q,&val))
	{
		printf("出队成功,出队的元素是%d\n",val);
	}
	else printf("出队失败");
	travel(&q);
	return 0;
} 
//初始化队列 
void init(que* pq)
{
	pq->pbase=(int *)malloc(len*sizeof(int));//初始化循环数组 
	pq->front=0;
	pq->rear=0;
}
//入队 
bool input(que* pq,int val)
{
	if(full_que(pq))	return false;
	else
	{
		pq->pbase[pq->rear]=val;
		pq->rear=(pq->rear+1)%len;			//相当于rear++ 
		return true;
	} 
} 
//判满 
bool full_que(que* pq)
{
	if((pq->rear+1)%len==pq->front)		return true ;
	else return false;
}
//遍历 
void travel(que* pq)
{
	int i=pq->front;			//用i来迭代,不然输出的时候front和rear就相等了,和遍历栈一样 
	while(i!=pq->rear)
	{
		printf("%4d",pq->pbase[i]);
		i=(i+1)%len;			//相当于i++ 
	}
	return; 
} 
//判空
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)		
	return true;
	else 	
	return false;
}

//出队 
bool out_que(que* pq,int* val)
{
	if(is_empty(pq))
	{
		printf("队列为空,出队失败\n");
		exit(-1); 
	}
	else
	{
		*val=pq->pbase[pq->front];			
		pq->front=(pq->front+1)%len;		//只需把front往前挪即可 
	}
	return true;
}
*/ 

//链表描述
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*pNode;
typedef struct queque
{
	pNode front;
	pNode rear;
}que;
//初始化 (空节点)
void init(que* pq)
{
	pq->front=(pNode)malloc(sizeof(Node));
	pq->rear=pq->front;
	pq->front->next=nullptr;
}
//入队 
bool input(que* pq,int val)
{
	pNode pNew=(pNode)malloc(sizeof(Node));
	if(pNew==nullptr)
	{
		printf("动态内存分配失败");
		exit(-1); 
	}
	pNew->data=val;
	pq->rear->next=pNew;
	pq->rear=pNew;
	pNew->next=nullptr;
	return true;
} 
//判空
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)	return true;
	else return false; 
} 
//出队 
bool outline(que* pq)
{
	int val; 
	pNode t=pq->front->next;
	pq->front->next=t->next;
	val=t->data; 
	free(t);
	printf("出队成功,出队元素为%d\n ",val);
}
//遍历
void travel(que* q)
{
	pNode t=q->front;
	while(t!=q->rear)
	{
		printf("%3d",t->next->data);
		t=t->next;
	}
	printf("\n");
} 
int main()
{
	que q;
	init(&q);
	if(is_empty)	printf("链表为空\n");
	input(&q,1);
	input(&q,2);
	input(&q,3);
	input(&q,0);
	travel(&q);
	outline(&q);
	travel(&q);
	return 0;
} 
