#include"RedBlackTree.h"

void Insert_Creat(RbRoot* Root, int key)
{
	pNode p_new;
	//����������ֵ��ͬ�Ľ��
	if (Rbtree_Search(Root->root, key) != nullptr)
	{
		exit(-1);		//error:д��return-1
	}
	p_new = Create_Rbtree_Node(key, NULL, NULL, NULL);	//����һ�����
	Insert_RBT(Root, p_new);	//���½��Ľ����뵽����
	return;
}
//���������½�����RB����
void Insert_RBT(RbRoot* Root, pNode& input_node)
{
	pNode p_leave = Root->root;
	pNode p_fa = nullptr;
	//����������������ѭ���ҵ�p_leave��p_father
	while (p_leave != nullptr)
	{
		p_fa = p_leave;
		if (input_node->data < p_leave->data)
			p_leave = p_leave->lchild;
		else
			p_leave = p_leave->rchild;
	}
	//��input����parent��ֵ
	input_node->parent = p_fa;
	//��p_fa�ĺ�����ֵ
	if (p_fa != nullptr)		//�ų�����һ����㶼û�е����
	{
		if (input_node->data < p_fa->data)
			p_fa->lchild = input_node;
		else
			p_fa->rchild = input_node;
	}
	else
		Root->root = input_node; //����һ����㶼û�о�ֱ���Ǹ��ڵ�

	//Ĭ�Ϻ�ɫ
	input_node->color = RED;
	//�޸�
	Rb_Insert_fix(Root, input_node);
}
//�������޸�
void Rb_Insert_fix(RbRoot* Root, pNode& p)
{
	pNode p_fa, p_gf;
	p_fa = p->parent;

	while (p_fa != nullptr && p_fa->color == RED)	//����  error:ѭ���޷�����
	{
		p_gf = p_fa->parent;
		if (p_fa == p_gf->lchild)	//����үү������
		{
			pNode p_uc = p_gf->rchild;	//�������Һ���
			//case1:�����Ǻ�ɫ(������첻�����Һ���)
			if (p_uc != nullptr && p_uc->color == RED)
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				p_uc->color = BLACK;
				p = p_gf;		//���游�����Ϊ��ǰ���
				continue;
			}
			//case2:���,��ǰ������Һ���
			else if (p_fa->rchild == p)
			{
				Left_Rotate(Root, p_fa);	//��ʱfatherָ���Ѿ�ָ������Ľ��
				pNode tmp;				//Ҫ�ѵ�ǰ���p��father����滻
				tmp = p_fa;
				p_fa = p;
				p = tmp;
			}
			//case3:���,��ǰ���������
			else
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				Right_Rotate(Root, p_gf);
			}
		}
		else //������үү���Һ���
		{
			pNode p_uc = p_gf->lchild;	//����������
			//case1:���(�����ֵ�ǰ�ڵ����ĸ�����)
			if (p_uc != nullptr && p_uc->color == RED)
			{
				p_uc->color = BLACK;
				p_fa->color = BLACK;
				p_gf->color = RED;
				p = p_gf;
				continue;
			}
			//case2:�����,�ҵ�ǰ������
			else if (p_fa->lchild == p)
			{
				Right_Rotate(Root, p_fa);
				pNode tmp;
				tmp = p_fa;
				p_fa = p;
				p = tmp;
			}
			//case3:�����Ǻ�ɫ,�ҵ�ǰ������Һ���
			else
			{
				p_fa->color = BLACK;
				p_gf->color = RED;
				Left_Rotate(Root, p_gf);
			}
		}
	}
	//�����ڵ���Ϊ��ɫ
	Root->root->color = BLACK;
}