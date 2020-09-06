/* 
//����������(�±�) 
#include<stdio.h>
#include<malloc.h>
struct tree
{
	char data;
	struct tree* plchild;
	struct tree* prchild;
}; 
struct tree* creat();
void pre_travel(struct tree* pt); 
void mid_travel(struct tree* pt);
void last_travel(struct tree* pt);
int main()
{
	struct tree* pt=creat();				//ֻҪ֪�����ڵ�ĵ�ַ�������������
//	pre_travel(pt); 
	mid_travel(pt);
//	last_travel(pt);
	return 0;
}
struct tree* creat(void)
{
	struct tree* pA=(struct tree*)malloc(sizeof(struct tree));
	struct tree* pB=(struct tree*)malloc(sizeof(struct tree));
	struct tree* pC=(struct tree*)malloc(sizeof(struct tree));
	struct tree* pD=(struct tree*)malloc(sizeof(struct tree));
	struct tree* pE=(struct tree*)malloc(sizeof(struct tree));
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	
	pA->plchild=pB;
	pB->plchild=pB->prchild=nullptr;
	pA->prchild=pC;
	pC->plchild=pD;
	pD->prchild=pE;
	pC->prchild=nullptr;
	pD->plchild=nullptr;
	pE->plchild=pE->prchild=nullptr;
	return pA;	
} 
//��ʵ���к�������Ĳ����ڷ��ʸ��ڵ�,�����ʸ��ڵ��ڳ�����������printf�������λ�� 

//������� 
void pre_travel(struct tree* pt)
{
	if(pt!=nullptr)							//�ǿ�ָ�����Ҫprintf data��			
	{
		printf("%c\n",pt->data);
		if(pt->plchild!=nullptr)
			pre_travel(pt->plchild);
		if(pt->prchild!=nullptr)
			pre_travel(pt->prchild);	
	}
} 
//���� 
void mid_travel(struct tree* pt)
{
	if(pt!=nullptr)						//����ָ��ֱ�ӽ�������		
	{
	
		if(pt->plchild!=nullptr)
			mid_travel(pt->plchild);
		printf("%c\n",pt->data);			
		if(pt->prchild!=nullptr)
			mid_travel(pt->prchild);	
	}
} 
//���� 
void last_travel(struct tree* pt)
{
	if(pt!=nullptr)						//����ָ�����Ҫprintf data��			
	{
		if(pt->plchild!=nullptr)
			pre_travel(pt->plchild);
		if(pt->prchild!=nullptr)
			pre_travel(pt->prchild);
		printf("%c\n",pt->data);	
	}
} 
*/ 

//�����㷨��Ӧ��---����������
#include<stdio.h>
#include<malloc.h>
typedef struct tree						//���������ʾ�� 
{
	char data;
	struct tree* rchild;
	struct tree* lchild; 
}tree,*pTree; 

void creat_tree(pTree& pt)	//ͨ�����������ָ��ĵ�ַ�Ӷ���main�е�pt���洴���ڵ� 
{
	char ch;
	ch=getchar();			//getcharһ��ֻ����һ��!!�ݹ�ʱ��!! 
	
	if(ch=='#')
	{
		pt=nullptr;
		return;
	}		
		
	else
	{
		pt=(pTree)malloc(sizeof(tree));	//�����ڵ� 
		pt->data =ch;					//data��ֵ 
		creat_tree(pt->lchild);		//�ݹ鴴�����ҽڵ� 
		creat_tree(pt->rchild);
	}
}	
//!!!ע�ⴴ����ʱ�������һ��Ҫ����������,��Ϊ�ݹ��㷨�ĳ�����nullptr
void pre_travel(pTree pt)
{
	if(pt!=nullptr)						//����Ϊ��ָ�����Ҫprintf data��			
	{	
			printf("%3c",pt->data);
		if(pt->lchild!=nullptr)
			pre_travel(pt->lchild);
		if(pt->rchild!=nullptr)
			pre_travel(pt->rchild);	
	}
} 
//������������ 
int depth(pTree pt)
{
	int l,r;
	if (pt==nullptr)
		return 0;
	else
	{
		l=depth(pt->lchild);		//��ڵ���� 
		r=depth(pt->rchild);		//�ҽڵ���� 
	}
	if(l>r)		//��Ⱦ���ѡ�����д��
		return (l+1);	//���շ��ص������+1��		
	else 
		return (r+1);		
} 
//��������Ľڵ���
int num_node(pTree pt)
{
	if(pt==nullptr)
		return 0;
	else
		return (num_node(pt->lchild)+num_node(pt->rchild)+1);//������+��+1
} 
//Ҷ�ӽ����
int yezi(pTree pt)
{
	if(pt==nullptr)	//�վͷ���0
		return 0;
	if(pt->lchild== nullptr && pt->rchild== nullptr)		//!!!ע:���ﲻ��д������== 
		return 1;
	else
		return yezi(pt->lchild)+yezi(pt->rchild);
} 
//����������
void copy_tree(pTree& pnew,pTree model)
{
	if (!model)
	{
		pnew = nullptr;
		return;
	}
	else
	{
		pnew = (pTree)malloc(sizeof(tree));		//error������ҼӶ������!!!
		pnew->data = model->data;
		copy_tree(pnew->lchild, model->lchild);
		copy_tree(pnew->rchild, model->rchild);
	}
}
//�ж��������Ƿ����
bool is_equal(pTree tree1, pTree tree2)
{
	if (!tree1 && !tree2)		//��Ϊ��
		return true;
	else if (!tree1 || !tree2)	//һ����һ������
		return false;
	else if(tree1->data==tree2->data)
	{
		return is_equal(tree1->lchild, tree2->lchild) && is_equal(tree1->rchild, tree2->rchild);
	}
	else
	{
		return false;
	}
}
//����ÿ��������������
void ChangeLR(pTree& pt)
{
	pTree temp;

	if (pt!=nullptr)	//���ǿվͿ��Խ������������������Ƿ�Ϊ��	
	{
		temp = pt->rchild;
		pt->rchild = pt->lchild;
		pt->lchild = temp;
		ChangeLR(pt->lchild);
		ChangeLR(pt->rchild);
	}
	else
	{
		return;
	}
}
int main()
{
	pTree pt1;			//creat����Ϊ�˲��������ָ�������ָ���е�ָ��
	pTree pt2;
	printf("�����������1��㣺\n"); 
	creat_tree(pt1);
	pre_travel(pt1);
	ChangeLR(pt1);
	pre_travel(pt1);
	//printf("��ö������������нڵ�Ϊ��");
	//pre_travel(pt1);
	//printf("\n");
	//printf("�������Ϊ%d\n",depth(pt1));
	//printf("���Ľڵ���Ϊ%d\n",num_node(pt1));
	//printf("����Ҷ�ӽڵ���Ϊ%d",yezi(pt1)); 
}
/*
//�������� 
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <memory.h>
int s1,s2;
typedef struct						//���������ʱ�����±�0,��1->2n 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}hfmt,*phfmt;						//phfmt+����ֱ�ӿ��Ե������� 

void init_hmf(phfmt* pph,int n)
{
	int i;
	if(n<=1)	return;				//һ���ڵ㹹��ë�߹������� 
	int m=2*n;						//����Ĵ�СΪ2n,�±�0����
	pph=(phfmt)malloc(sizeof(hfmt)*m);
	memset(*pph,0,sizeof(hfmt)*m);	//��ʼ��Ϊ0 
	for(i=1;i<=n;i++)
	{
		printf("�������i���ڵ��Ȩֵ:"); 
		scanf("%d",*pph[i]);
	} 
}
void select(phfmt ph,int n)
{
	int i,val,val1;
	for(i=1,val=100;i<=n;i++)				//����Сֵ 
	{
		if(ph[i].parent!=0)	break;
		if(ph[i].weight<val && ph[i].parent==0)
		{
			val=ph[i].weight;
			s1=i;
		}	
	}
	val1=val;
	for(i=1,val=100;i<=n;i++)
	{
		if(ph[i].parent!=0)	break;
		if(ph[i].weight<val && ph[i].weight>val1 && ph[i].parent==0)
		{
			s2=i;
		}	
	}	
} 
void combine(phfmt* pph,int n)
{
	int m=2*n,i;
	
	for(i=n+1;i<=m;i++)
	{
		select(*pph,n);
		*pph[s1]->parent=i;
		*pph[s2]->parent=i;
		*pph[i]->lchild=s1;
		*pph[i]->rchild=s2;
		*pph[i]->weight=*pph[s1].weight+*pph[s2].weight;
	}
} 
int main()
{
	phfmt pha=nullptr;
	int n,i;
	printf("����Ҷ�ӽڵ�ĸ���:");
	scanf("%d",&n); 
	init_hmf(&pha,n);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	combine(&pha,n);
	for(i=1;i<=n;i++)
	{
		printf("%d",pha[i].weight);						//��ΪҪ�����ṹ������,����main��һ��Ҫ��ָ�� 
	} 
	return 0;
}
*/
