#include"RedBlackTree.h"
//根据某个值在RB树中找到结点
void Delete_Rb(RbRoot* Root, int key)
{
	pNode z;
	if ((z = Rbtree_Search_FR(Root, key)) != nullptr)
		Rb_Delete(Root, z);
}
//根据找到对应键值的结点进行删除操作
void Rb_Delete(RbRoot* Root, pNode& p)	
{
	pNode p_c, p_fa;	//p_c是replace的右孩子,也需要调整(replace没有左孩子)
	int color;
	//case1:被删除结点左右结点都不为空的情况
	if ((p->lchild != nullptr) && (p->rchild != nullptr))
	{
		//用后继结点(右子树的最左)取代,并删除取代结点
		pNode replace = p->rchild;	//要找右子树的最左
		//找到后继replace
		while (replace->lchild != nullptr)	//条件一定是左子树不为空,而不是自己不为空
			replace = replace->lchild;
		//待删结点不是根节点:将待删结点前驱的指针直接指向替代结点?
		if (p->parent != nullptr)
		{
			if (p->parent->lchild == p)
				p->parent->lchild = replace;
			else
				p->parent->rchild = replace;
		}
		//当前节点是根节点,就更新根节点即可
		else
			Root->root = replace;

		p_c = replace->rchild;	//替代节点的右孩子
		p_fa = replace->parent;	//替代节点的父亲域
		color = replace->color;	//保存下取代结点的颜色
		//被删除结点是它后继节点的父亲
		if (p_fa == p)
		{
			p_fa = replace;
		}
		else	//待删结点不是后继的父亲
		{	//replace只可能有右孩子
			if (p_c != nullptr)
				p_c->parent = p_fa;
			// replace上位前把右孩子交给它爷爷安顿
			p_fa->lchild = p_c;
			//上位
			replace->rchild = p->rchild;
			p->rchild->parent = replace;
		}

		replace->parent = p->parent;
		replace->color = p->color;
		replace->lchild = p->lchild;
		p->lchild->parent = replace;

		if (color == BLACK)
			Rb_Delete_Fix(Root, p_c, p_fa);
		delete p;	//将结点删除
		p = nullptr;
		return;
	}
	//case2:一个孩子的情况(把父亲删了后,爷爷带孙子)
	if (p->lchild != nullptr || p->rchild != nullptr)
	{
		(p->lchild != nullptr) ? p_c = p->lchild : p_c = p->rchild; 	//p_c是待删结点的儿子
		p_fa = p->parent;	//待删结点的父亲
		color = p->color;
		p_c->parent = p_fa;	//父亲没了,儿子的长辈直接是爷爷
		//对p_fa(爷爷)的信息进行修改
		if (p_fa != nullptr)
		{
			(p_fa->lchild == p) ? p_fa->lchild = p_c : p_fa->rchild = p_c;
		}
		else //待删结点没有父亲,说明就是根节点
			Root->root = p_c;
		//修复
		if (color == BLACK)
			Rb_Delete_Fix(Root, p_c, p_fa);
		free(p);
		p = nullptr;
	}
}
//删除后的修复操作
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
				// Case 1: x的兄弟w是红色的  
				other->color = BLACK;
				p_fa->color = RED;
				Left_Rotate(Root, p_fa);
				other = p_fa->rchild;
			}
			if ((!other->lchild || other->lchild->color == BLACK) &&
				(!other->rchild || other->rchild->color == BLACK))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
				other->color = RED;
				p = p_fa;
				p_fa = p->parent;
			}
			else
			{
				if (!other->rchild || other->rchild->color == BLACK)
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
					other->color = BLACK;
					other->color = RED;
					Right_Rotate(Root, other);
					other = p_fa->rchild;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
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