#define RED        0    // 红色节点
#define BLACK    1    // 黑色节点
#include<stdio.h>
#include<stdlib.h>
typedef struct RBTreeNode {
	unsigned char color;        // 颜色(RED 或 BLACK)
	int  data;                    // 关键字(键值)
	struct RBTreeNode* lchild;    // 左孩子
	struct RBTreeNode* rchild;    // 右孩子
	struct RBTreeNode* parent;    // 父结点
}Node, * pNode;

typedef struct rb_root {
	pNode root;
}RbRoot;
//红黑树专有函数
void Left_Rotate(RbRoot* Root, pNode& p);	//左旋
void Right_Rotate(RbRoot* Root, pNode& p);	//右旋
void Insert_RBT(RbRoot* Root,pNode& input_node);	//在RB树中以结点为单位插入
void Rb_Insert_fix(RbRoot* Root, pNode& input_node);	//插入后修复
void Rb_Delete(RbRoot* Root, pNode& p);		//以结点删除
void Rb_Delete_Fix(RbRoot* Root, pNode& p_c, pNode& p_fa);	//删除后修复
//删除值为key的元素
void Delete_Rb(RbRoot* root, int key);
// 创建红黑树，返回"红黑树的根"！
RbRoot* Create_Rbtree();
// 销毁红黑树
void Destroy_Rbtree(pNode p);
// 前序遍历"红黑树"
void Preorder_Rbtree(pNode p);
void Preorder_From_Root(RbRoot* Root);
// (递归实现)查找"红黑树"中键值为key的节点。找到的话，返回0；否则，返回-1。
pNode Rbtree_Search(pNode p, int key);
pNode Rbtree_Search_FR(RbRoot *Root, int key);
// 返回最小结点的值(将值保存到val中)。找到的话，返回0；否则返回-1。
int Rbtree_Minimum(RbRoot* root, int* val);
// 打印红黑树
void Print_Rbtree(pNode p);
void Print_Rbtree_FR(RbRoot *Root);
// 将key插入到结点
void Insert_Creat(RbRoot* Root, int key);	//
//创建结点
pNode Create_Rbtree_Node(int key, pNode parent, pNode lchild, pNode rchild);

