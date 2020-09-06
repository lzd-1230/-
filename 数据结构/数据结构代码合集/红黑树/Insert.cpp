#include"RedBlackTree.h"

void Insert_Creat(RbRoot* Root, int key)
{
	pNode p_new;
	//不允许插入键值相同的结点
	if (Rbtree_Search(Root->root, key) != nullptr)
	{
		exit(-1);		//error:写成return-1
	}
	p_new = Create_Rbtree_Node(key, NULL, NULL, NULL);	//创建一个结点
	Insert_RBT(Root, p_new);	//把新建的结点插入到树中
	return;
}
//将创建的新结点加入RB树中
void Insert_RBT(RbRoot* Root, pNode& input_node)
{
	pNode p_leave = Root->root;
	pNode p_fa = nullptr;
	//二叉搜索树的性质循环找到p_leave和p_father
	while (p_leave != nullptr)
	{
		p_fa = p_leave;
		if (input_node->data < p_leave->data)
			p_leave = p_leave->lchild;
		else
			p_leave = p_leave->rchild;
	}
	//给input结点的parent域赋值
	input_node->parent = p_fa;
	//给p_fa的孩子域赋值
	if (p_fa != nullptr)		//排除现在一个结点都没有的情况
	{
		if (input_node->data < p_fa->data)
			p_fa->lchild = input_node;
		else
			p_fa->rchild = input_node;
	}
	else
		Root->root = input_node; //现在一个结点都没有就直接是根节点

	//默认红色
	input_node->color = RED;
	//修复
	Rb_Insert_fix(Root, input_node);
}
//插入后的修复
void Rb_Insert_fix(RbRoot* Root, pNode& p)
{
	pNode p_fa, p_gf;
	p_fa = p->parent;

	while (p_fa != nullptr && p_fa->color == RED)	//父红  error:循环无法结束
	{
		p_gf = p_fa->parent;
		if (p_fa == p_gf->lchild)	//且是爷爷的左孩子
		{
			pNode p_uc = p_gf->rchild;	//叔叔是右孩子
			//case1:叔叔是红色(父红叔红不分左右孩子)
			if (p_uc != nullptr && p_uc->color == RED)
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				p_uc->color = BLACK;
				p = p_gf;		//将祖父结点设为当前结点
				continue;
			}
			//case2:叔黑,当前结点是右孩子
			else if (p_fa->rchild == p)
			{
				Left_Rotate(Root, p_fa);	//此时father指针已经指向下面的结点
				pNode tmp;				//要把当前结点p和father结点替换
				tmp = p_fa;
				p_fa = p;
				p = tmp;
			}
			//case3:叔黑,当前结点是左孩子
			else
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				Right_Rotate(Root, p_gf);
			}
		}
		else //父亲是爷爷的右孩子
		{
			pNode p_uc = p_gf->lchild;	//叔叔是左孩子
			//case1:叔红(不区分当前节点是哪个孩子)
			if (p_uc != nullptr && p_uc->color == RED)
			{
				p_uc->color = BLACK;
				p_fa->color = BLACK;
				p_gf->color = RED;
				p = p_gf;
				continue;
			}
			//case2:叔叔黑,且当前是左孩子
			else if (p_fa->lchild == p)
			{
				Right_Rotate(Root, p_fa);
				pNode tmp;
				tmp = p_fa;
				p_fa = p;
				p = tmp;
			}
			//case3:叔叔是黑色,且当前结点是右孩子
			else
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				Left_Rotate(Root, p_gf);
			}
		}
	}
	//将根节点设为黑色
	Root->root->color = BLACK;
}