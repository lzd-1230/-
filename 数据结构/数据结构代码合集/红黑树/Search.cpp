#include"RedBlackTree.h"

//从根开始根据键值去找
pNode Rbtree_Search_FR(RbRoot* Root, int key)
{
	if (Root != nullptr)
		return Rbtree_Search(Root->root, key);
}
//二叉搜索树的搜索方法
pNode Rbtree_Search(pNode p, int key)
{
	if (p == nullptr || p->data == key)
		return p;
	if (key < p->data)
		return Rbtree_Search(p->lchild, key);
	else
		return Rbtree_Search(p->rchild, key);
}

