//����ջ��ʵ�ֱ���(����)	(ʧ��) 
/*
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//���Ľ�� 
typedef struct tree
{
	char data;
	struct tree* plchild;
	struct tree* prchild;
}tree,*ptree;
//ջ�Ľ�� 
typedef struct Node
{
	ptree data;
	struct Node* pNext;	
}Node,*PNode;
//ջ��ָ�� 
typedef struct Stack
{
	PNode ptop;
	PNode pbottom;
}stack,*pstack;
ptree creat();
void travel(ptree);
ptree creat_list(); 
void push(pstack,char);
bool pop(pstack ,char* );
int main()
{
	ptree p=creat();
	travel(p);
	return 0; 
}
ptree creat()
{
	ptree pA=(ptree)malloc(sizeof(tree));
	ptree pB=(ptree)malloc(sizeof(tree));
	ptree pC=(ptree)malloc(sizeof(tree));
	ptree pD=(ptree)malloc(sizeof(tree));
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pA->plchild=pB;
	pA->prchild=pC;
	pB->prchild=pD;
	pB->plchild=NULL;
	pC->plchild=pC->prchild=NULL;
	pD->plchild=pD->prchild=NULL;
	return pA;
}
bool is_empty(pstack p)
{
	if(p->pbottom==p->ptop)				//bottom��top�Ƿ���� 
	{
		printf("ջΪ��\n");
		return true; 
	}
	else return false; 
} 

void push(pstack p,ptree pt)
{
	PNode pNew=(PNode)malloc(sizeof(Node));			//�����½ڵ� 
	pNew->data=pt;									//data��ֵ 
	pNew->pNext=p->ptop;							//ָ����ֵ 
	p->ptop=pNew;									//ptop�ĸ��� 
} 

bool pop(pstack p ,ptree pval )
{
	if(is_empty(p))	return false;
	else
	{
		PNode t=p->ptop;
		pval=p->ptop->data; 
		p->ptop=p->ptop->pNext; 		//��ptop��������ֱ��������һ�� 
		free(t);						//��Ҫ�ǵ�free�ռ� 
		t=NULL;
	}
} 

init_stack(pstack p)
{
	p->ptop=(PNode)malloc(sizeof(Node));	//�½��ڵ� 
	if(NULL==p->ptop)						 
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1); 
	}
	
	else
	{
		p->pbottom=p->ptop;					//��ptop��pbottom��ֵ��� 
		p->ptop->pNex t=NULL;				//��ptop��Ϊ������Ľڵ� 
	}	
}
void travel(ptree p)
{
	stack s;
	init_stack(&s);
	
	ptree t=p;					//ʹtָ����ڵ� 
	ptree val;				 
	
	while(p||!is_empty(&s))
	{
		if(p)
		{
			push(&s,t);
			t=t->plchild;
		}
		else
		{
			pop(&s,val);
			printf("%c",val->data);
			t=t->prchild;
		}
	}
}
*/
