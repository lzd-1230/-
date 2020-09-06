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
	PNode P=pHead->pNext;				//P�д�ŵ����׽ڵ�ĵ�ַ		
	while(P!=NULL)						//ע������,����P->pNext!=NULL 
	{
		printf("%d\n",P->data); 
		P=P->pNext;						//��Pָ����һ���ڵ� 
	}
	return; 
}
		
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

void MergeList(PNode &La,PNode &Lb, PNode &Lc)
{
	//˫�����ʼ��Ϊ�׽ڵ� 
	PNode pa=La->pNext;
	PNode pb=Lb->pNext;
	
	PNode t;
	PNode pc=La;					//pc���ΪLc����β�ڵ�
	Lc=pc; 							//������La��ͷ�����Ϊ�Լ���ͷ��� 
	//��������ԭ����pa��pb����ǰһ��,��˽�pc->pNext�޸Ĳ���Ӱ�쵽pa,pb���������� 
	while(pa && pb)					//�����߶���Ϊ�� 
	{
		if(pa->data>pb->data)		//�Ƚϴ�С 
		//��pc����һ��ֱ��ָ��pb�Ľ�� 
		{ 
			pc->pNext=pb;			//ÿ�ζ�pc->pNext���в�������ʹpc�Ľ�����Լ����뷨 
			pc=pb;					//��pcʼ��ָ���������ĩ��
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
			free(pb);			//free����˼�ǰ�pbָ��Ľ���ͷ���,��pb�Դ���,���Լ�����������ַ��ֵ 
			pb=t;			
		}
	}
	while(pa || pb) 		//����֮���зǿյ� 
	{
		if(pa)
		{
			pc->pNext=pa;
			pc=pa;
			pa=pa->pNext;	
		}
		else
		{
			pc->pNext=pb;			//ÿ�ζ�pc->pNext���в�������ʹpc�Ľ�����Լ����뷨 
			pc=pb;					//��pcʼ��ָ���������ĩ��
			pb=pb->pNext;
		}
	}
}
//�ݹ�д��
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
