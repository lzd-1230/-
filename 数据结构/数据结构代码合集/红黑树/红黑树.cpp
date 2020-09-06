#include"RedBlackTree.h"
#include<stdio.h>
int main()
{
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int i, len = 9;
	RbRoot* root = nullptr;
	root = Create_Rbtree();
	for (i = 0; i < len; i++)
	{
		Insert_Creat(root, a[i]);
		printf("添加节点:%d\n", a[i]);
		printf("此时树的信息: \n");
		Print_Rbtree_FR(root);
		printf("\n");
	}
	printf("前序遍历:");
	Preorder_From_Root(root);
	printf("\n");
	Delete_Rb(root, a[8]);
	printf("前序遍历:");
	Preorder_From_Root(root);
	return 0;
}





