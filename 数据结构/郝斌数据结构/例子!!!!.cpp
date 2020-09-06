#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(node) 
//����������Ķ���������ṹ
typedef struct node {
	char data;
	struct node *lchild;
	struct node *rchild;
} tree,*ptree;
//�����������д����ڵ�
void Creatptree(ptree *root) {
	char ch;
	ch = getchar();
	if(ch=='#') {	//# ����սڵ�
		*root = NULL;
		return;
	}
	else{
		*root = (ptree)malloc(LEN);
		(*root)->data = ch;
		Creatptree(&((*root)->lchild));
		Creatptree(&((*root)->rchild));
		
	}
}

//�������������,rootΪָ����������ڵ��ָ��
void Preorder(ptree root) {

	if(root==NULL) return;
//		���ʸ��ڵ�
	if(root->data!='#')		printf("%c",root->data);
	Preorder(root->lchild);
	Preorder(root->rchild);
}

int main() {
	ptree root=NULL;
	printf("�������������㣺");
	Creatptree(&root);
	printf("��ö������������нڵ�Ϊ��");
	Preorder(root);
	return 0;
}

