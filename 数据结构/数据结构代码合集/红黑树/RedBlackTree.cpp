#include "RedBlackTree.h"
#include <stdlib.h>







void Right_Rotate(RbRoot *Root, pNode& p)
{
	//yΪ��ǰ��������
	pNode y = p->lchild;

	p->lchild = y->rchild;
	if (y->rchild != nullptr)
		y->rchild->parent = p;
	y->rchild = p;			//p�ҵ�y������
	y->parent = p->parent;	//��p��parent��y��parent

	//��p�ĸ���Ӧ����ô��ֵ
	if (p->parent == nullptr)		//pԭ�����Ǹ�
		Root->root = y;
	else if (p->parent->lchild == p)	//p������
		p->parent->lchild = y;
	else
		p->parent->rchild = y;

	p->parent = y;
}

void Left_Rotate(RbRoot *Root, pNode& p)	//pָ��ǰ�ڵ�,rootָ���ڵ�
{
	//yΪ��ǰ��������
	pNode y = p->rchild;

	p->rchild = y->lchild;
	if (y->lchild != nullptr)	//y�����ӷǿյĻ���Ҫ����һ������ָ��
		y->lchild->parent = p;
	y->lchild = p;			//p�ҵ�y������
	y->parent = p->parent;	//��p��parent��y��parent

	//��p�ĸ���Ӧ����ô��ֵ
	if (p->parent == nullptr)		//pԭ�����Ǹ�
		Root->root = y;
	else if (p->parent->lchild == p)	//p������
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

// ��ӡ�����
void Print_Rbtree(pNode p,int key,int direction)	//direction�ڵݹ�ʱ��ֵ
{
	if(p != nullptr)
     {
         if(direction==0)    // tree�Ǹ��ڵ�
             printf("%2d(B) is root\n", p->data);
        else                // tree�Ƿ�֧�ڵ�
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




