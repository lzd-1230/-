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
	duo* elem;				//���������е��׵�ַ 
	int length;				//��ǰ���� 
}Sqlist; 
//��ʼ��
List initlist()
{
	List P;
	P=(List)malloc(sizeof(Sqlist));			//��̬һά����
	 
	return P;								//���ص�ַ 
}
int main()
{
	List P;
	P=initlist();
	P->length=3;
	printf("%d",P->length);
	return 0;
} */ 

//����

typedef struct Node
{
	int data;
	struct Node* pNext;	
}Node,*PNode;				//Node�ȼ��ڽṹ������ PNode�ȼ��ڽṹ��ָ������ 

PNode creat_list();							//��������ʼ������ 
void travel_list(PNode pHead);				//�������� 
bool is_empty(PNode pHead);					//�ж��Ƿ�Ϊ�� 
int ;				//�������� 
bool insert(PNode pHead,int pos,int val);	//�������в���ĳֵ 
bool delete_list(PNode pHead,int pos);		//ɾ��ĳλ���ϵ�ֵ 
void sort_list(PNode pHead);				//����  
int main()
{
	PNode pHead=creat_list();				//��������ʼ������ 
	insert(pHead,2,1230);
	delete_list(pHead,1);
	sort_list(pHead);
	travel_list(pHead);						//�������� 
	printf("����ĳ���Ϊ%d",length_list(pHead));
	return 0;
} 
//����
/*
��ѭ��֮ǰ����"��̬��"β�ڵ�,��ѭ���в��ϸ���,��֤ÿ�������Ľڵ�Ϊβ�ڵ� 
*/ 
PNode creat_list()
{
	int len;
	int val;
	int i;
	printf("����������ĳ���:");
	scanf("%d",&len);
	if(len<=0)
	{
		printf("������Ч");
		exit(-1); 
	}
	PNode pHead=NULL;
	pHead=(PNode)malloc(sizeof(Node));
	pHead->pNext=NULL;
	PNode pTail=pHead;
	
	for(i=0;i<len;i++)
	{
		PNode pNew=(PNode)malloc(sizeof(Node));
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		scanf("%d",&val);
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;		
	}
	return pHead;	
} 
//�ж��Ƿ�Ϊ��
bool is_empty(PNode pHead)
{
	if(pHead==NULL)	return true;
	else return false;
} 
//�������� 
/*
�ٶ�������˵��ʼ���൱����pָ���׽ڵ�
�ڶԱ���������˵��ֹ�൱��p==NULL 
��cnt=0;��p=pHead->pNext��Ӧ 
*/ 
void travel_list(PNode pHead)
{
	int i=0;
	//�ж��Ƿ�Ϊ��
	if(is_empty(pHead))
	{
		printf("����Ϊ��"); 
	}
	PNode p=pHead->pNext;
	while(p!=NULL)
	{
		printf("��%d��Ԫ�ص�ֵΪ:%d\n",i+1,p->data);
		p=p->pNext;	
		i++;
	}				
	return; 
} 
//������ĳ��� 
//ע��cnt=0;��p=pHead->pNext��Ӧ  !! 
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
//�����posǰ����
/*
����ҵ������λ��ǰһ���ڵ�? 
cnt=0;��p=pHead->pNext��Ӧ��,��cnt=0ѭ����cnt=pos-1

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
		printf("����ʧ��"); 
		return false; 
	}
	New->data=val;
	New->pNext=t->pNext;
	t->pNext=New;
	printf("�ѽ�%d�����%d��λ��\n",val,pos);	
	return true;
}
//ɾ��ĳλ���ϵ�ֵ 
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

//����(ѡ������)
/*�ؼ���������forѭ����Ҫ���з���,��i=0�����pָ���׽ڵ�
 ��i++�����p=p->pNext
 ����ָ�ں��潫����������дһ�� 
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
