#include "RedBlackTree.h"
#include <stdlib.h>







void Right_Rotate(RbRoot *Root, pNode& p)
{
	//y为当前结点的右子
	pNode y = p->lchild;

	p->lchild = y->rchild;
	if (y->rchild != nullptr)
		y->rchild->parent = p;
	y->rchild = p;			//p挂到y的左子
	y->parent = p->parent;	//将p的parent给y的parent

	//看p的父亲应该怎么赋值
	if (p->parent == nullptr)		//p原来就是根
		Root->root = y;
	else if (p->parent->lchild == p)	//p是左孩子
		p->parent->lchild = y;
	else
		p->parent->rchild = y;

	p->parent = y;
}

void Left_Rotate(RbRoot *Root, pNode& p)	//p指当前节点,root指根节点
{
	//y为当前结点的右子
	pNode y = p->rchild;

	p->rchild = y->lchild;
	if (y->lchild != nullptr)	//y的左孩子非空的话还要多设一个父亲指针
		y->lchild->parent = p;
	y->lchild = p;			//p挂到y的左子
	y->parent = p->parent;	//将p的parent给y的parent

	//看p的父亲应该怎么赋值
	if (p->parent == nullptr)		//p原来就是根
		Root->root = y;
	else if (p->parent->lchild == p)	//p是左孩子
		p->parent->lchild = y;
	else
		p->parent->rchild = y;

	p->parent = y;
}

void Destroy_Rbtree(pNode p)
{
	if (p == nullptr)
		return;

	if (p->lchild != nullptr)
		Destroy_Rbtree(p->lchild);
	else if (p->rchild != nullptr)
		Destroy_Rbtree(p->rchild);
	free(p);
	p = nullptr;
}
void Preorder_Rbtree(pNode p)
{
	if (p != nullptr)
	{
		printf("%5d", p->data);
		Preorder_Rbtree(p->lchild);
		Preorder_Rbtree(p->rchild);
	}
}
void Preorder_From_Root(RbRoot* Root)
{
	if (Root != nullptr)
		Preorder_Rbtree(Root->root);
}

// 打印红黑树
void Print_Rbtree(pNode p,int key,int direction)	//direction在递归时赋值
{
	if(p != nullptr)
     {
         if(direction==0)    // tree是根节点
             printf("%2d(B) is root\n", p->data);
        else                // tree是分支节点
             printf("%2d(%s) is %2d's %6s child\n", p->data, p->color==RED?"R":"B", key, direction==1?"right" : "left");
 
         Print_Rbtree(p->lchild, p->data, -1);
         Print_Rbtree(p->rchild,p->data,  1);
     }
}
void Print_Rbtree_FR(RbRoot *Root)
{
	if (Root != nullptr && Root->root != nullptr)
		Print_Rbtree(Root->root, Root->root->data, 0);
}




