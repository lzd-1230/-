//利用栈来实现遍历(中序)	(失败) 
/*
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//树的结点 
typedef struct tree
{
	char data;
	struct tree* plchild;
	struct tree* prchild;
}tree,*ptree;
//栈的结点 
typedef struct Node
{
	ptree data;
	struct Node* pNext;	
}Node,*PNode;
//栈的指针 
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
	if(p->pbottom==p->ptop)				//bottom和top是否相等 
	{
		printf("栈为空\n");
		return true; 
	}
	else return false; 
} 

void push(pstack p,ptree pt)
{
	PNode pNew=(PNode)malloc(sizeof(Node));			//创建新节点 
	pNew->data=pt;									//data域赋值 
	pNew->pNext=p->ptop;							//指针域赋值 
	p->ptop=pNew;									//ptop的更新 
} 

bool pop(pstack p ,ptree pval )
{
	if(is_empty(p))	return false;
	else
	{
		PNode t=p->ptop;
		pval=p->ptop->data; 
		p->ptop=p->ptop->pNext; 		//让ptop从最上面直接往下移一个 
		free(t);						//但要记得free空间 
		t=NULL;
	}
} 

init_stack(pstack p)
{
	p->ptop=(PNode)malloc(sizeof(Node));	//新建节点 
	if(NULL==p->ptop)						 
	{
		printf("动态内存分配失败");
		exit(-1); 
	}
	
	else
	{
		p->pbottom=p->ptop;					//让ptop和pbottom的值相等 
		p->ptop->pNex t=NULL;				//让ptop成为最上面的节点 
	}	
}
void travel(ptree p)
{
	stack s;
	init_stack(&s);
	
	ptree t=p;					//使t指向根节点 
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
