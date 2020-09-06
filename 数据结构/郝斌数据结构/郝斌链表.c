#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;			//Node�ȼ��ڽṹ������ PNode�ȼ��ڽṹ��ָ������ 

PNode creat_list();							//��������ʼ������ 
void travel_list(PNode pHead);				//�������� 
bool is_empty(PNode pHead);					//�ж��Ƿ�Ϊ�� 
int length_list(PNode pHead);				//�������� 
bool insert(PNode pHead,int pos,int val);	//�������в���ĳֵ 
bool delete_list(PNode pHead,int pos);		//ɾ��ĳλ���ϵ�ֵ 
void sort_list(PNode pHead);				//���� 
int main()	
{
	PNode pHead=NULL;
	pHead=creat_list();		//����һ������
	if(is_empty(pHead))
		printf("����Ϊ��\n");
	sort_list(pHead);
	insert(pHead,2,1230); 
	travel_list(pHead); 	//�������� 
	delete_list(pHead,2);
	travel_list(pHead);
	printf("����ĳ���Ϊ%d\n",length_list(pHead));
	return 0;
}
//��������
PNode creat_list()
{
	int i;
	int len;			//���������Ч�ڵ�ĸ��� 
	int val;			//������ʱ���������������ֵ 
	printf("����������Ľڵ���:len=");
	scanf("%d",&len);
	
	PNode pHead=(PNode)malloc(sizeof(Node));	//����һ��ͷ���
	if(pHead==NULL)
	{
		printf("ͷ������ʧ��,������ֹ\n");
		exit(-1); 
	} 
	
	PNode pTail=pHead;								//��ʼ��βָ�� 
	pTail->pNext=NULL; 								//��֤βָ���ָ����Ϊ�� 
	for(i=0;i<len;i++)
	{
		printf("�������%d���ڵ��ֵ",i+1); 
		scanf("%d",&val);
		PNode pNew=(PNode)malloc(sizeof(Node));		//�����½ڵ�洢���� 
			if(pNew==NULL)
			{
				printf("ͷ������ʧ��,������ֹ\n");
				exit(-1); 
			} 
		pNew->data=val;					//����������ݸ����ýڵ������� 
		pTail->pNext=pNew;				//��pNew�ҵ�β�ڵ����� 
		pNew->pNext=NULL;				//��pNewָ�������,����µ�β�ڵ� 
		pTail=pNew; 					//ÿ�ε�pNew����һ���ڵ���˵����β�ڵ� 
	}
	return pHead;						//�����Ƿ���creat������pHead 
}
//�������� 
void travel_list(PNode pHead)
{
	PNode P=pHead->pNext;				//P�д�ŵ����׽ڵ�ĵ�ַ		
	while(P!=NULL)						//ע������,����P->pNext!=NULL 
	{
		printf("%d\n",P->data); 
		P=P->pNext;						//��Pָ����һ���ڵ� 
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
//�������� 
int length_list(PNode pHead)
{
	int cnt=0;
	PNode P=pHead->pNext;			//�׽ڵ㿪ʼ 
	while(P!=NULL)
	{
		cnt++;
		P=P->pNext;
	}
	return cnt;
} 
//���������� 
void sort_list(PNode pHead)
{
	int len=length_list(pHead);
	PNode P,Q;
	P=pHead;
	int i,j,t;
	for(i=0,P=P->pNext;i<len-1;i++,P=P->pNext)		//�����м������������,���߶�һ������ 
	{
		for(Q=P->pNext,j=i+1;j<len;j++,Q=Q->pNext)
		{
			if(Q->data>P->data)						//���治�ܱ�ǰ���,�̽��� 
			{
				t=P->data;
				P->data=Q->data;
				Q->data=t;
			}
		}
	}
} 
//�������в���
bool insert(PNode pHead,int pos,int val)	//��posǰ�����val 
{
	if(pos>length_list(pHead))
	{
		printf("�����λ����Ч\n");
		exit(-1);
	} 
	int i=0;
	PNode p=pHead;
	while(NULL!=p && i<pos-1)		//��posǰ�����  
	{
		i++;
		p=p->pNext;
	}
	if(i>pos-1||pHead==NULL)
	{
		printf("�����λ�û���������,����ʧ��"); 
		return false; 
	}
	
	PNode q=p->pNext;						//q����һ���ڵ� 
	PNode tNew=(PNode)malloc(sizeof(Node));
	if(tNew==NULL)
	{
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1); 
	} 
	tNew->pNext=q;
	p->pNext=tNew;
	tNew->data=val;
	return true; 
} 
//ɾ��������ĳλ�õ�Ԫ��
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
