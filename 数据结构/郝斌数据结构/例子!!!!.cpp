#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(node) 
//定义二叉树的二叉链表结点结构
typedef struct node {
	char data;
	struct node *lchild;
	struct node *rchild;
} tree,*ptree;
//按照先序序列创建节点
void Creatptree(ptree *root) {
	char ch;
	ch = getchar();
	if(ch=='#') {	//# 代表空节点
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

//先序遍历二叉树,root为指向二叉树根节点的指针
void Preorder(ptree root) {

	if(root==NULL) return;
//		访问根节点
	if(root->data!='#')		printf("%c",root->data);
	Preorder(root->lchild);
	Preorder(root->rchild);
}

int main() {
	ptree root=NULL;
	printf("请输入二叉树结点：");
	Creatptree(&root);
	printf("这棵二叉树先序排列节点为：");
	Preorder(root);
	return 0;
}

