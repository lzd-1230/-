//����������(������)
//Debug:ע��Ҫ�޸ĵı����ͽ������ķ�ʽһ��Ҫ�����û�ָ��
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

pBtreNode find(pBtreNode, NodeType);		//�����������Ĳ���
void insert_tree(pBtreNode&, NodeType);
void init_Btree(pBtreNode&, NodeType*, int);
void mid_travel(pBtreNode pt);
void Delete(pBtreNode& T);
void Delete1(pBtreNode& T);		//���ݺ���������޸ĵ�
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
//����
void insert_tree(pBtreNode& T, NodeType key)
{
	pBtreNode s;
	if (!find(T, key))				//����ʧ�ܲ���Ҫ����
	{
		s = (pBtreNode)malloc(sizeof(BtreNode));
		s->data = key;
		s->prchild = s->plchild = NULL;

		if (T == NULL)					//���ĵ�ǰ�����Ϊ������Ϊ���ڵ����
			T = s;
		else if (key > T->data)		//���ĵ�ǰ��㲻Ϊ���Ҵ�,���Ҳ�
			insert_tree(T->prchild, key);
		else if (key < T->data)		//���ĵ�ǰ��㲻Ϊ����С,�����
			insert_tree(T->plchild, key);
	}
}

//����
pBtreNode find(const pBtreNode T, NodeType key)
{
	if (T == NULL || key == T->data)	//T==NULL˵���ݹ鵽���Ҳû���ҵ�key,����NULL
		return T;
	else if (key < T->data)
		find(T->plchild, key);
	else if (key > T->data)
		find(T->prchild, key);
}
//����
void init_Btree(pBtreNode& T, NodeType a[], int len)
{
	int i;
	T = NULL;
	for (i = 0; i < len; i++)
	{
		insert_tree(T, a[i]);
	}
}
//���� 
void mid_travel(pBtreNode pt)
{
	if (pt != NULL)						//����ָ��ֱ�ӽ�������		
	{

		if (pt->plchild != NULL)
			mid_travel(pt->plchild);
		printf("%d\n", pt->data);
		if (pt->prchild != NULL)
			mid_travel(pt->prchild);
	}
}
//ɾ��
void Delete(pBtreNode& T)
{
	pBtreNode m, s;			//m����ָ���ɾ�����,����һ����ڴ��ͷ�
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
	else 			//������������Ϊ��
	{
		m = T;
		s = T->plchild;	//ѭ����sָ����������ڵ��λ��
		while (s->prchild != NULL)
		{
			m = s; 			//s�����m��������,mһ����s��ǰ�� 
			s = s->prchild;
		}

		T->data = s->data;	//���������ֵ����
		 
		if (m != T)
			m->prchild = s->plchild;
		else
			m->plchild = s->prchild;
		free(s);
	}
}
void Delete1(pBtreNode& p)
{
	pBtreNode p_c, p_fa;	//p_c��replace���Һ���,Ҳ��Ҫ����(replaceû������)
	int color;
	//case1:��ɾ��������ҽ�㶼��Ϊ�յ����
	if ((p->plchild != nullptr) && (p->prchild != nullptr))
	{
		//�ú�̽��(������������)ȡ��,��ɾ��ȡ�����
		p_fa = p;
		pBtreNode replace = p->prchild;	//Ҫ��������������
		//�ҵ����replace
		while (replace->plchild != nullptr)	//����һ������������Ϊ��,�������Լ���Ϊ��
		{
			p_fa = replace;
			replace = replace->plchild;
		}
		p_c = replace->prchild;	//����ڵ���Һ���
		//��ɾ�����������̽ڵ�ĸ���
		if (p_fa == p)
		{
			p_fa = replace;
		}
		else	//��ɾ��㲻�Ǻ�̵ĸ���
		{	//replaceֻ�������Һ���
			if (p_c != nullptr)// replace��λǰ���Һ��ӽ�����үү����
				p_fa->plchild = p_c;
			//��λ
			replace->prchild = p->prchild;
		}

		replace->plchild = p->plchild;

		delete p;	//�����ɾ��
		p = nullptr;
		return;
	}
	//case2:һ�����ӵ����(�Ѹ���ɾ�˺�,үү������)
	else if (p->plchild != nullptr || p->prchild != nullptr)
	{
		(p->plchild != nullptr) ? p_c = p->plchild : p_c = p->prchild; 	//p_c�Ǵ�ɾ���Ķ���
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
		if (key == T->data)		//�ҵ��ؼ���,ִ��ɾ������
			return Delete1(T);
		else if (key > T->data)	//��������������
			Delete_Find(T->prchild, key);
		else if (key < T->data)	//����С��������
			Delete_Find(T->plchild, key);
	}
}



