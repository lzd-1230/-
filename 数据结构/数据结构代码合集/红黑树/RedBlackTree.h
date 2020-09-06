#define RED        0    // ��ɫ�ڵ�
#define BLACK    1    // ��ɫ�ڵ�
#include<stdio.h>
#include<stdlib.h>
typedef struct RBTreeNode {
	unsigned char color;        // ��ɫ(RED �� BLACK)
	int  data;                    // �ؼ���(��ֵ)
	struct RBTreeNode* lchild;    // ����
	struct RBTreeNode* rchild;    // �Һ���
	struct RBTreeNode* parent;    // �����
}Node, * pNode;

typedef struct rb_root {
	pNode root;
}RbRoot;
//�����ר�к���
void Left_Rotate(RbRoot* Root, pNode& p);	//����
void Right_Rotate(RbRoot* Root, pNode& p);	//����
void Insert_RBT(RbRoot* Root,pNode& input_node);	//��RB�����Խ��Ϊ��λ����
void Rb_Insert_fix(RbRoot* Root, pNode& input_node);	//������޸�
void Rb_Delete(RbRoot* Root, pNode& p);		//�Խ��ɾ��
void Rb_Delete_Fix(RbRoot* Root, pNode& p_c, pNode& p_fa);	//ɾ�����޸�
//ɾ��ֵΪkey��Ԫ��
void Delete_Rb(RbRoot* root, int key);
// ���������������"������ĸ�"��
RbRoot* Create_Rbtree();
// ���ٺ����
void Destroy_Rbtree(pNode p);
// ǰ�����"�����"
void Preorder_Rbtree(pNode p);
void Preorder_From_Root(RbRoot* Root);
// (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ㡣�ҵ��Ļ�������0�����򣬷���-1��
pNode Rbtree_Search(pNode p, int key);
pNode Rbtree_Search_FR(RbRoot *Root, int key);
// ������С����ֵ(��ֵ���浽val��)���ҵ��Ļ�������0�����򷵻�-1��
int Rbtree_Minimum(RbRoot* root, int* val);
// ��ӡ�����
void Print_Rbtree(pNode p);
void Print_Rbtree_FR(RbRoot *Root);
// ��key���뵽���
void Insert_Creat(RbRoot* Root, int key);	//
//�������
pNode Create_Rbtree_Node(int key, pNode parent, pNode lchild, pNode rchild);

