#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//˳��洢�ṹ(ѭ������) 
/* 
int len =10;
typedef struct queque
{
	int * pbase;				//ѭ������ 
	int front;					//front �� rear���൱�������±� 
	int rear;					//rearָ�������һ��Ԫ�ؽ�����λ��,��λ��û��Ԫ��!! 
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
		printf("���ӳɹ�,���ӵ�Ԫ����%d\n",val);
	}
	else printf("����ʧ��");
	travel(&q);
	return 0;
} 
//��ʼ������ 
void init(que* pq)
{
	pq->pbase=(int *)malloc(len*sizeof(int));//��ʼ��ѭ������ 
	pq->front=0;
	pq->rear=0;
}
//��� 
bool input(que* pq,int val)
{
	if(full_que(pq))	return false;
	else
	{
		pq->pbase[pq->rear]=val;
		pq->rear=(pq->rear+1)%len;			//�൱��rear++ 
		return true;
	} 
} 
//���� 
bool full_que(que* pq)
{
	if((pq->rear+1)%len==pq->front)		return true ;
	else return false;
}
//���� 
void travel(que* pq)
{
	int i=pq->front;			//��i������,��Ȼ�����ʱ��front��rear�������,�ͱ���ջһ�� 
	while(i!=pq->rear)
	{
		printf("%4d",pq->pbase[i]);
		i=(i+1)%len;			//�൱��i++ 
	}
	return; 
} 
//�п�
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)		
	return true;
	else 	
	return false;
}

//���� 
bool out_que(que* pq,int* val)
{
	if(is_empty(pq))
	{
		printf("����Ϊ��,����ʧ��\n");
		exit(-1); 
	}
	else
	{
		*val=pq->pbase[pq->front];			
		pq->front=(pq->front+1)%len;		//ֻ���front��ǰŲ���� 
	}
	return true;
}
*/ 

//��������
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
//��ʼ�� (�սڵ�)
void init(que* pq)
{
	pq->front=(pNode)malloc(sizeof(Node));
	pq->rear=pq->front;
	pq->front->next=nullptr;
}
//��� 
bool input(que* pq,int val)
{
	pNode pNew=(pNode)malloc(sizeof(Node));
	if(pNew==nullptr)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1); 
	}
	pNew->data=val;
	pq->rear->next=pNew;
	pq->rear=pNew;
	pNew->next=nullptr;
	return true;
} 
//�п�
bool is_empty(que* pq)
{
	if(pq->front==pq->rear)	return true;
	else return false; 
} 
//���� 
bool outline(que* pq)
{
	int val; 
	pNode t=pq->front->next;
	pq->front->next=t->next;
	val=t->data; 
	free(t);
	printf("���ӳɹ�,����Ԫ��Ϊ%d\n ",val);
}
//����
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
	if(is_empty)	printf("����Ϊ��\n");
	input(&q,1);
	input(&q,2);
	input(&q,3);
	input(&q,0);
	travel(&q);
	outline(&q);
	travel(&q);
	return 0;
} 
