/* 
//遍历二叉树(郝斌) 
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
	struct tree* pt=creat();				//只要知道根节点的地址即可造出二叉树
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
//其实先中后序遍历的差别就在访问根节点,而访问根节点在程序中体现在printf数据域的位置 

//先序遍历 
void pre_travel(struct tree* pt)
{
	if(pt!=nullptr)							//非空指针才需要printf data域			
	{
		printf("%c\n",pt->data);
		if(pt->plchild!=nullptr)
			pre_travel(pt->plchild);
		if(pt->prchild!=nullptr)
			pre_travel(pt->prchild);	
	}
} 
//中序 
void mid_travel(struct tree* pt)
{
	if(pt!=nullptr)						//若空指针直接结束调用		
	{
	
		if(pt->plchild!=nullptr)
			mid_travel(pt->plchild);
		printf("%c\n",pt->data);			
		if(pt->prchild!=nullptr)
			mid_travel(pt->prchild);	
	}
} 
//后序 
void last_travel(struct tree* pt)
{
	if(pt!=nullptr)						//若空指针才需要printf data域			
	{
		if(pt->plchild!=nullptr)
			pre_travel(pt->plchild);
		if(pt->prchild!=nullptr)
			pre_travel(pt->prchild);
		printf("%c\n",pt->data);	
	}
} 
*/ 

//遍历算法的应用---建立二叉树
#include<stdio.h>
#include<malloc.h>
typedef struct tree						//二叉链表表示法 
{
	char data;
	struct tree* rchild;
	struct tree* lchild; 
}tree,*pTree; 

void creat_tree(pTree& pt)	//通过操作传入的指针的地址从而在main中的pt后面创建节点 
{
	char ch;
	ch=getchar();			//getchar一次只接受一个!!递归时用!! 
	
	if(ch=='#')
	{
		pt=nullptr;
		return;
	}		
		
	else
	{
		pt=(pTree)malloc(sizeof(tree));	//创建节点 
		pt->data =ch;					//data域赋值 
		creat_tree(pt->lchild);		//递归创建左右节点 
		creat_tree(pt->rchild);
	}
}	
//!!!注意创建的时候输入的一定要是满二叉树,因为递归算法的出口是nullptr
void pre_travel(pTree pt)
{
	if(pt!=nullptr)						//若不为空指针才需要printf data域			
	{	
			printf("%3c",pt->data);
		if(pt->lchild!=nullptr)
			pre_travel(pt->lchild);
		if(pt->rchild!=nullptr)
			pre_travel(pt->rchild);	
	}
} 
//求二叉树的深度 
int depth(pTree pt)
{
	int l,r;
	if (pt==nullptr)
		return 0;
	else
	{
		l=depth(pt->lchild);		//左节点深度 
		r=depth(pt->rchild);		//右节点深度 
	}
	if(l>r)		//深度就是选两边中大的
		return (l+1);	//最终返回的深度是+1的		
	else 
		return (r+1);		
} 
//求二叉树的节点数
int num_node(pTree pt)
{
	if(pt==nullptr)
		return 0;
	else
		return (num_node(pt->lchild)+num_node(pt->rchild)+1);//返回左+右+1
} 
//叶子结点数
int yezi(pTree pt)
{
	if(pt==nullptr)	//空就返回0
		return 0;
	if(pt->lchild== nullptr && pt->rchild== nullptr)		//!!!注:这里不能写成两个== 
		return 1;
	else
		return yezi(pt->lchild)+yezi(pt->rchild);
} 
//复制两颗树
void copy_tree(pTree& pnew,pTree model)
{
	if (!model)
	{
		pnew = nullptr;
		return;
	}
	else
	{
		pnew = (pTree)malloc(sizeof(tree));		//error别随便乱加定义符号!!!
		pnew->data = model->data;
		copy_tree(pnew->lchild, model->lchild);
		copy_tree(pnew->rchild, model->rchild);
	}
}
//判断两棵树是否相等
bool is_equal(pTree tree1, pTree tree2)
{
	if (!tree1 && !tree2)		//都为空
		return true;
	else if (!tree1 || !tree2)	//一个空一个不空
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
//交换每个结点的左右子树
void ChangeLR(pTree& pt)
{
	pTree temp;

	if (pt!=nullptr)	//不是空就可以交换不关心左右子树是否为空	
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
	pTree pt1;			//creat函数为了操作外面的指针必须用指针中的指针
	pTree pt2;
	printf("请输入二叉树1结点：\n"); 
	creat_tree(pt1);
	pre_travel(pt1);
	ChangeLR(pt1);
	pre_travel(pt1);
	//printf("这棵二叉树先序排列节点为：");
	//pre_travel(pt1);
	//printf("\n");
	//printf("树的深度为%d\n",depth(pt1));
	//printf("树的节点数为%d\n",num_node(pt1));
	//printf("树的叶子节点数为%d",yezi(pt1)); 
}
/*
//哈夫曼树 
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <memory.h>
int s1,s2;
typedef struct						//构造数组的时候不用下标0,从1->2n 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}hfmt,*phfmt;						//phfmt+变量直接可以当作数组 

void init_hmf(phfmt* pph,int n)
{
	int i;
	if(n<=1)	return;				//一个节点构造毛线哈夫曼树 
	int m=2*n;						//数组的大小为2n,下标0不用
	pph=(phfmt)malloc(sizeof(hfmt)*m);
	memset(*pph,0,sizeof(hfmt)*m);	//初始化为0 
	for(i=1;i<=n;i++)
	{
		printf("情输入第i个节点的权值:"); 
		scanf("%d",*pph[i]);
	} 
}
void select(phfmt ph,int n)
{
	int i,val,val1;
	for(i=1,val=100;i<=n;i++)				//找最小值 
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
	printf("输入叶子节点的个数:");
	scanf("%d",&n); 
	init_hmf(&pha,n);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	combine(&pha,n);
	for(i=1;i<=n;i++)
	{
		printf("%d",pha[i].weight);						//因为要创建结构体数组,所以main中一定要用指针 
	} 
	return 0;
}
*/
