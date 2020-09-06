//二叉排序树(待运行)
//Debug:注意要修改的变量送进函数的方式一定要是引用或指针
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree* plchild;
	struct tree* prchild;
}BtreNode, * pBtreNode;
typedef int NodeType;

pBtreNode find(pBtreNode, NodeType);		//二叉排序树的查找
void insert_tree(pBtreNode&, NodeType);
void init_Btree(pBtreNode&, NodeType*, int);
void mid_travel(pBtreNode pt);
void Delete(pBtreNode& T);
void Delete1(pBtreNode& T);		//根据红黑树代码修改的
void Delete_Find(pBtreNode& T, int key);
int main()
{
	int a[5] = { 3,2,4,1,5 };
	int len = 5;
	pBtreNode T = NULL;
	init_Btree(T, a, len);
	mid_travel(T);
	Delete_Find(T, 1);
	mid_travel(T);
	return 0;
}
//插入
void insert_tree(pBtreNode& T, NodeType key)
{
	pBtreNode s;
	if (!find(T, key))				//查找失败才需要插入
	{
		s = (pBtreNode)malloc(sizeof(BtreNode));
		s->data = key;
		s->prchild = s->plchild = NULL;

		if (T == NULL)					//树的当前结点若为空则作为根节点插入
			T = s;
		else if (key > T->data)		//树的当前结点不为空且大,往右插
			insert_tree(T->prchild, key);
		else if (key < T->data)		//树的当前结点不为空且小,往左插
			insert_tree(T->plchild, key);
	}
}

//查找
pBtreNode find(const pBtreNode T, NodeType key)
{
	if (T == NULL || key == T->data)	//T==NULL说明递归到最后也没有找到key,返回NULL
		return T;
	else if (key < T->data)
		find(T->plchild, key);
	else if (key > T->data)
		find(T->prchild, key);
}
//生成
void init_Btree(pBtreNode& T, NodeType a[], int len)
{
	int i;
	T = NULL;
	for (i = 0; i < len; i++)
	{
		insert_tree(T, a[i]);
	}
}
//中序 
void mid_travel(pBtreNode pt)
{
	if (pt != NULL)						//若空指针直接结束调用		
	{

		if (pt->plchild != NULL)
			mid_travel(pt->plchild);
		printf("%d\n", pt->data);
		if (pt->prchild != NULL)
			mid_travel(pt->prchild);
	}
}
//删除
void Delete(pBtreNode& T)
{
	pBtreNode m, s;			//m用于指向待删除结点,便于一会的内存释放
	if (T->plchild == NULL)
	{
		m = T;
		T = T->plchild;
		free(m);
	}
	else if (T->prchild == NULL)
	{
		m = T;
		T = T->prchild;
		free(m);
	}
	else 			//左右子树都不为空
	{
		m = T;
		s = T->plchild;	//循环后s指向最终替代节点的位置
		while (s->prchild != NULL)
		{
			m = s; 			//s最后是m的右子树,m一定是s的前驱 
			s = s->prchild;
		}

		T->data = s->data;	//把替代结点的值给它
		 
		if (m != T)
			m->prchild = s->plchild;
		else
			m->plchild = s->prchild;
		free(s);
	}
}
void Delete1(pBtreNode& p)
{
	pBtreNode p_c, p_fa;	//p_c是replace的右孩子,也需要调整(replace没有左孩子)
	int color;
	//case1:被删除结点左右结点都不为空的情况
	if ((p->plchild != nullptr) && (p->prchild != nullptr))
	{
		//用后继结点(右子树的最左)取代,并删除取代结点
		p_fa = p;
		pBtreNode replace = p->prchild;	//要找右子树的最左
		//找到后继replace
		while (replace->plchild != nullptr)	//条件一定是左子树不为空,而不是自己不为空
		{
			p_fa = replace;
			replace = replace->plchild;
		}
		p_c = replace->prchild;	//替代节点的右孩子
		//被删除结点是它后继节点的父亲
		if (p_fa == p)
		{
			p_fa = replace;
		}
		else	//待删结点不是后继的父亲
		{	//replace只可能有右孩子
			if (p_c != nullptr)// replace上位前把右孩子交给它爷爷安顿
				p_fa->plchild = p_c;
			//上位
			replace->prchild = p->prchild;
		}

		replace->plchild = p->plchild;

		delete p;	//将结点删除
		p = nullptr;
		return;
	}
	//case2:一个孩子的情况(把父亲删了后,爷爷带孙子)
	else if (p->plchild != nullptr || p->prchild != nullptr)
	{
		(p->plchild != nullptr) ? p_c = p->plchild : p_c = p->prchild; 	//p_c是待删结点的儿子
		pBtreNode tmp = p;
		p = p_c;
		free(tmp);
		tmp = nullptr;
	}
	else
	{
		free(p);
		p = nullptr;
	}
}
void Delete_Find(pBtreNode& T, int key)
{
	if (T == NULL)
		return;
	else
	{
		if (key == T->data)		//找到关键字,执行删除操作
			return Delete1(T);
		else if (key > T->data)	//比它大找右子树
			Delete_Find(T->prchild, key);
		else if (key < T->data)	//比它小找左子树
			Delete_Find(T->plchild, key);
	}
}



