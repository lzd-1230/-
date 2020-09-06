#include"RedBlackTree.h"
//����ĳ��ֵ��RB�����ҵ����
void Delete_Rb(RbRoot* Root, int key)
{
	pNode z;
	if ((z = Rbtree_Search_FR(Root, key)) != nullptr)
		Rb_Delete(Root, z);
}
//�����ҵ���Ӧ��ֵ�Ľ�����ɾ������
void Rb_Delete(RbRoot* Root, pNode& p)	
{
	pNode p_c, p_fa;	//p_c��replace���Һ���,Ҳ��Ҫ����(replaceû������)
	int color;
	//case1:��ɾ��������ҽ�㶼��Ϊ�յ����
	if ((p->lchild != nullptr) && (p->rchild != nullptr))
	{
		//�ú�̽��(������������)ȡ��,��ɾ��ȡ�����
		pNode replace = p->rchild;	//Ҫ��������������
		//�ҵ����replace
		while (replace->lchild != nullptr)	//����һ������������Ϊ��,�������Լ���Ϊ��
			replace = replace->lchild;
		//��ɾ��㲻�Ǹ��ڵ�:����ɾ���ǰ����ָ��ֱ��ָ��������?
		if (p->parent != nullptr)
		{
			if (p->parent->lchild == p)
				p->parent->lchild = replace;
			else
				p->parent->rchild = replace;
		}
		//��ǰ�ڵ��Ǹ��ڵ�,�͸��¸��ڵ㼴��
		else
			Root->root = replace;

		p_c = replace->rchild;	//����ڵ���Һ���
		p_fa = replace->parent;	//����ڵ�ĸ�����
		color = replace->color;	//������ȡ��������ɫ
		//��ɾ�����������̽ڵ�ĸ���
		if (p_fa == p)
		{
			p_fa = replace;
		}
		else	//��ɾ��㲻�Ǻ�̵ĸ���
		{	//replaceֻ�������Һ���
			if (p_c != nullptr)
				p_c->parent = p_fa;
			// replace��λǰ���Һ��ӽ�����үү����
			p_fa->lchild = p_c;
			//��λ
			replace->rchild = p->rchild;
			p->rchild->parent = replace;
		}

		replace->parent = p->parent;
		replace->color = p->color;
		replace->lchild = p->lchild;
		p->lchild->parent = replace;

		if (color == BLACK)
			Rb_Delete_Fix(Root, p_c, p_fa);
		delete p;	//�����ɾ��
		p = nullptr;
		return;
	}
	//case2:һ�����ӵ����(�Ѹ���ɾ�˺�,үү������)
	if (p->lchild != nullptr || p->rchild != nullptr)
	{
		(p->lchild != nullptr) ? p_c = p->lchild : p_c = p->rchild; 	//p_c�Ǵ�ɾ���Ķ���
		p_fa = p->parent;	//��ɾ���ĸ���
		color = p->color;
		p_c->parent = p_fa;	//����û��,���ӵĳ���ֱ����үү
		//��p_fa(үү)����Ϣ�����޸�
		if (p_fa != nullptr)
		{
			(p_fa->lchild == p) ? p_fa->lchild = p_c : p_fa->rchild = p_c;
		}
		else //��ɾ���û�и���,˵�����Ǹ��ڵ�
			Root->root = p_c;
		//�޸�
		if (color == BLACK)
			Rb_Delete_Fix(Root, p_c, p_fa);
		free(p);
		p = nullptr;
	}
}
//ɾ������޸�����
void Rb_Delete_Fix(RbRoot* Root, pNode& p, pNode& p_fa)
{
	pNode other;

	while ((p == nullptr || p->color == BLACK) && p != Root->root)
	{
		if (p_fa->lchild == p)
		{
			other = p_fa->rchild;
			if (other->color == RED)
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��  
				other->color = BLACK;
				p_fa->color = RED;
				Left_Rotate(Root, p_fa);
				other = p_fa->rchild;
			}
			if ((!other->lchild || other->lchild->color == BLACK) &&
				(!other->rchild || other->rchild->color == BLACK))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
				other->color = RED;
				p = p_fa;
				p_fa = p->parent;
			}
			else
			{
				if (!other->rchild || other->rchild->color == BLACK)
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
					other->color = BLACK;
					other->color = RED;
					Right_Rotate(Root, other);
					other = p_fa->rchild;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				other->color = p_fa->color;
				p_fa->color = BLACK;
				other->rchild->color = BLACK;
				Right_Rotate(Root, p_fa);
				p = Root->root;
				break;
			}
		}
	}
	if (p)
		p->color = BLACK;
}