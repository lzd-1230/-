#include"RedBlackTree.h"
//���ݼ�ֵ�������,���ؽ���ָ��
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
//�����յĸ��ڵ�
RbRoot* Create_Rbtree()
{
	RbRoot* Root = new RbRoot;
	Root->root = nullptr;
	return Root;
}