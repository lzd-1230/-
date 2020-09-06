#include"RedBlackTree.h"
//根据键值创建结点,返回结点的指针
pNode Create_Rbtree_Node(int key, pNode parent, pNode lchild, pNode rchild)
{
	pNode p;
	if ((p = new Node) == nullptr)
		return nullptr;
	p->data = key;
	p->lchild = lchild;
	p->rchild = rchild;
	p->parent = parent;
	p->color = BLACK;
	return p;
}
//创建空的根节点
RbRoot* Create_Rbtree()
{
	RbRoot* Root = new RbRoot;
	Root->root = nullptr;
	return Root;
}