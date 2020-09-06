#include"RedBlackTree.h"

//�Ӹ���ʼ���ݼ�ֵȥ��
pNode Rbtree_Search_FR(RbRoot* Root, int key)
{
	if (Root != nullptr)
		return Rbtree_Search(Root->root, key);
}
//��������������������
pNode Rbtree_Search(pNode p, int key)
{
	if (p == nullptr || p->data == key)
		return p;
	if (key < p->data)
		return Rbtree_Search(p->lchild, key);
	else
		return Rbtree_Search(p->rchild, key);
}

