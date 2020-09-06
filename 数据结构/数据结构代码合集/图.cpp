//����
//�汾һ:ѭ�����б�ʾ��

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iostream>
using namespace std;
int len = 10;	//ʵ����ʹ�õ�ֻ��4���ռ�
typedef struct queque
{
	int* pbase;				//ѭ������ 
	int front;					//front �� rear���൱�������±� 
	int rear;					//rearָ�������һ��Ԫ�ؽ�����λ��,��λ��û��Ԫ��!! 
}Que, * PQue;

using namespace std;
typedef struct Graph
{
	char vertex[100];			//�����
	int arcs[100][100];			//�ڽӾ���
	int num_v, num_a;			//Ŀǰ�Ѿ�ʹ�õĶ������ͱߵ���Ŀ
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
	cout << "û���ҵ��ö���" << endl;
	exit(-1);
}
//�������Ĺ���
void Creat_G(AMG& G)
{
	//��ʼ������
	cout << "�����붥�����:";
	cin >> G.num_v;
	cout << "������ߵĸ���";
	cin >> G.num_a;
	//���붥���
	cout << "�����붥����Ϣ:";
	getchar();			//�Ե��س�
	for (int i = 0; i < G.num_v; i++)
	{
		G.vertex[i] = getchar();
	}
	//��ʼ���ڽӾ���
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
		cout << "�������" << i + 1 << "���ߵ�:v1 v2 Ȩֵ" << endl;
		cin >> v1 >> v2 >> w;
		//�ҵ������ڶ������±�
		i_v1 = locate(G, v1);
		i_v2 = locate(G, v2);
		//�Գ�λ�ø�ֵ	
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
		cout << "��������,�޷�����" << endl;
		exit(-1);
	}
	pQ->pbase[pQ->rear] = val;
	pQ->rear = (pQ->rear + 1) % len;
}

void out_que(PQue pQ, int* val)
{
	if (is_Empty(pQ))
	{
		cout << "����Ϊ��,����ʧ��" << endl;
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
		cout << "��" << i + 1 << "��Ԫ��Ϊ" << pQ->pbase[(pQ->front + i) % len] << endl;
		pQ->front = (pQ->front + 1) % len;
	}
}

void init(PQue pQ)//�ٸ��������ռ�������α�ָ��ͬһ��λ��
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
	cout << "�ѷ��ʽ��" << G.vertex[5] << endl;
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
				cout << "�ѷ��ʽ��:" << G.vertex[i] << endl;
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