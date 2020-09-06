#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAX_NUM 100//最大数字个数为100
#define inf 20000000 //最大值为
using namespace std;
/*知识点:引用
	本质是一个更安全更方便的指针,因为定义的时候必须要初始化,不会出现野指针
	而且使用的时候不用加*就可以对所引用的值进行修改,避免了多重指针的*混乱问题
	记住一句话"r引用了a,r就是a的别名"
*/
typedef struct {
	unsigned int weight;//权值 
	unsigned int parent, lchild, rchild;//父节点，孩子结点的权值 
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;				//二维字符数组 
int s1, s2;								//最小的两个结点 

void Select(const HuffmanTree& HT, int n) {	//选出无父结点，并且权值最小的两个结点，赋值给s1，s2 
	int i, min1 = inf, min2 = inf;
	for (i = 1; i <= n; i++)
	{					//找最小 
		if (HT[i].weight < min1 && HT[i].parent == 0)
		{
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	for (i = 1; i <= n; i++) {			//找次小 
		if (HT[i].weight < min2 && i != s1 && HT[i].parent == 0)
		{
			min2 = HT[i].weight;
			s2 = i;
		}
	}
}

//n是字符集
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n) {//根据输入的结点的权值和个数来构建赫夫曼树 //创建数 和编码的地址
	if (n <= 1)return;
	int m = 2 * n - 1;				//完全二叉树n个叶子，有2*n-1个结点 
	int i;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	//0号单元未用 开辟空间
	for (i = 1; i <= n; i++, w++)
	{										//叶子结点初始化
		HT[i].weight = *w;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (; i <= m; i++)
	{										//非叶子结点初始化 
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
//一开始n个结点,每次循环插入一个,每循环一次,i就要多一个
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1);		//选出权值最小的两个叶子节点生成一个新节点

		HT[s1].parent = i;
		HT[s2].parent = i;

		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	//----------下面是将每个结点的赫夫曼编码存入二维字符数组

	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//这里先申请了第一维 
	char* cd = (char*)malloc(n * sizeof(char));			//申请一段临时工作空间 
	cd[n - 1] = '\0';									//分支最多n-1个 
	for (i = 1; i <= n; i++) {							//有n个叶子节点要编码
		int start = n - 1, c, f;						//倒序存入
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{												//从叶子到根逆向求编码 
			if (HT[f].lchild == c)
				cd[--start] = '0';						//如果当前结点是父节点的左孩子，则存一个1 
			else
				cd[--start] = '1';						//反之给1 
		}												//注意每一次循环start都在递减
		HC[i] = (char*)malloc((n - start) * sizeof(char));	//对每一个一维再次申请第二维 
		strcpy_s(HC[i],strlen(&cd[start])+1,&cd[start]);	//+1代表加上空字符的长度					//将编码从工作空间存入赫夫曼编码表中 
	}
	free(cd); //释放临时空间 
}


int main() {
	HuffmanTree HT;					//自定义结构体  ht
	HuffmanCode HC;
	int w[MAX_NUM], n;
	int i;
	printf("输入结点的个数:\n");
	scanf_s("%d", &n);
	printf("输入每个结点的权值:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	HuffmanCoding(HT, HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("%d的赫夫曼编码为：%s\n", HT[i].weight, HC[i]);
	}
	return 0;
}