//队列
//版本一:循环队列表示法

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iostream>
using namespace std;
int len = 10;	//实际能使用的只有4个空间
typedef struct queque
{
	int* pbase;				//循环数组 
	int front;					//front 和 rear都相当于数组下标 
	int rear;					//rear指向的是下一个元素进来的位置,该位置没有元素!! 
}Que, * PQue;

using namespace std;
typedef struct Graph
{
	char vertex[100];			//顶点表
	int arcs[100][100];			//邻接矩阵
	int num_v, num_a;			//目前已经使用的顶点数和边的数目
}AMG;


bool is_Empty(PQue);
bool is_full(PQue);
void init(PQue);
void out_que(PQue, int*);
void input(PQue pQ, int val);
void travel(PQue);
void Creat_G(AMG& G);
int locate(AMG G, char v);
void BFS(AMG G, int* visited, Que& q);

int locate(AMG G, char v)
{
	int i;
	for (i = 0; i < G.num_v; i++)
	{
		if (G.vertex[i] == v)
			return i;
	}
	cout << "没有找到该顶点" << endl;
	exit(-1);
}
//无向网的构造
void Creat_G(AMG& G)
{
	//初始化个数
	cout << "请输入顶点个数:";
	cin >> G.num_v;
	cout << "请输入边的个数";
	cin >> G.num_a;
	//输入顶点表
	cout << "请输入顶点信息:";
	getchar();			//吃掉回车
	for (int i = 0; i < G.num_v; i++)
	{
		G.vertex[i] = getchar();
	}
	//初始化邻接矩阵
	for (int i = 0; i < G.num_v; i++)
	{
		for (int j = 0; j < G.num_v; j++)
		{
			if (i == j)
				G.arcs[i][j] = 0;
			else
				G.arcs[i][j] = 999;
		}
	}
	int w;
	char v1, v2;
	int i_v1, i_v2;
	for (int i = 0; i < G.num_a; i++)
	{
		cout << "请输入第" << i + 1 << "条边的:v1 v2 权值" << endl;
		cin >> v1 >> v2 >> w;
		//找到顶点在顶点表的下标
		i_v1 = locate(G, v1);
		i_v2 = locate(G, v2);
		//对称位置赋值	
		G.arcs[i_v1][i_v2] = w;
		G.arcs[i_v2][i_v1] = w;
	}
}
bool is_full(PQue pQ)
{
	if ((pQ->rear + 1) % len == pQ->front)
		return true;
	else
		return false;
}
void input(PQue pQ, int val)
{
	if (is_full(pQ))
	{
		cout << "队列已满,无法插入" << endl;
		exit(-1);
	}
	pQ->pbase[pQ->rear] = val;
	pQ->rear = (pQ->rear + 1) % len;
}

void out_que(PQue pQ, int* val)
{
	if (is_Empty(pQ))
	{
		cout << "队列为空,出队失败" << endl;
		exit(-1);
	}
	*val = pQ->pbase[pQ->front];
	pQ->front = (pQ->front + 1) % len;
}

void travel(PQue pQ)
{
	int i = 0;
	while (pQ->front != pQ->rear)
	{
		cout << "第" << i + 1 << "个元素为" << pQ->pbase[(pQ->front + i) % len] << endl;
		pQ->front = (pQ->front + 1) % len;
	}
}

void init(PQue pQ)//①给数组分配空间②两个游标指向同一个位置
{
	pQ->pbase = new int[len];
	pQ->front = pQ->rear = 0;
}

bool is_Empty(PQue pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
void BFS(AMG G, int* visited, Que& q)
{
	cout << "已访问结点" << G.vertex[5] << endl;
	visited[5] = 1;
	input(&q, 5);
	int out_temp;
	while (!is_Empty(&q))
	{
		out_que(&q, &out_temp);
		for (int i = 0; i < G.num_v; i++)
		{
			if (G.arcs[out_temp][i] < 999 && out_temp != i && !visited[i])
			{
				visited[i] = 1;
				cout << "已访问结点:" << G.vertex[i] << endl;
				input(&q, i);
			}
		}
	}
}
int main()
{
	Que q;
	init(&q);
	AMG G;
	Creat_G(G);
	int* visited = new int[G.num_v];
	memset(visited, 0, G.num_v * sizeof(int));
	BFS(G, visited,q);
}