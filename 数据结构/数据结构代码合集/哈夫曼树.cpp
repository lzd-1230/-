#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAX_NUM 100//������ָ���Ϊ100
#define inf 20000000 //���ֵΪ
using namespace std;
/*֪ʶ��:����
	������һ������ȫ�������ָ��,��Ϊ�����ʱ�����Ҫ��ʼ��,�������Ұָ��
	����ʹ�õ�ʱ���ü�*�Ϳ��Զ������õ�ֵ�����޸�,�����˶���ָ���*��������
	��סһ�仰"r������a,r����a�ı���"
*/
typedef struct {
	unsigned int weight;//Ȩֵ 
	unsigned int parent, lchild, rchild;//���ڵ㣬���ӽ���Ȩֵ 
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;				//��ά�ַ����� 
int s1, s2;								//��С��������� 

void Select(const HuffmanTree& HT, int n) {	//ѡ���޸���㣬����Ȩֵ��С��������㣬��ֵ��s1��s2 
	int i, min1 = inf, min2 = inf;
	for (i = 1; i <= n; i++)
	{					//����С 
		if (HT[i].weight < min1 && HT[i].parent == 0)
		{
			min1 = HT[i].weight;
			s1 = i;
		}
	}
	for (i = 1; i <= n; i++) {			//�Ҵ�С 
		if (HT[i].weight < min2 && i != s1 && HT[i].parent == 0)
		{
			min2 = HT[i].weight;
			s2 = i;
		}
	}
}

//n���ַ���
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n) {//��������Ľ���Ȩֵ�͸����������շ����� //������ �ͱ���ĵ�ַ
	if (n <= 1)return;
	int m = 2 * n - 1;				//��ȫ������n��Ҷ�ӣ���2*n-1����� 
	int i;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	//0�ŵ�Ԫδ�� ���ٿռ�
	for (i = 1; i <= n; i++, w++)
	{										//Ҷ�ӽ���ʼ��
		HT[i].weight = *w;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (; i <= m; i++)
	{										//��Ҷ�ӽ���ʼ�� 
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
//һ��ʼn�����,ÿ��ѭ������һ��,ÿѭ��һ��,i��Ҫ��һ��
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1);		//ѡ��Ȩֵ��С������Ҷ�ӽڵ�����һ���½ڵ�

		HT[s1].parent = i;
		HT[s2].parent = i;

		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	//----------�����ǽ�ÿ�����ĺշ�����������ά�ַ�����

	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//�����������˵�һά 
	char* cd = (char*)malloc(n * sizeof(char));			//����һ����ʱ�����ռ� 
	cd[n - 1] = '\0';									//��֧���n-1�� 
	for (i = 1; i <= n; i++) {							//��n��Ҷ�ӽڵ�Ҫ����
		int start = n - 1, c, f;						//�������
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{												//��Ҷ�ӵ������������ 
			if (HT[f].lchild == c)
				cd[--start] = '0';						//�����ǰ����Ǹ��ڵ�����ӣ����һ��1 
			else
				cd[--start] = '1';						//��֮��1 
		}												//ע��ÿһ��ѭ��start���ڵݼ�
		HC[i] = (char*)malloc((n - start) * sizeof(char));	//��ÿһ��һά�ٴ�����ڶ�ά 
		strcpy_s(HC[i],strlen(&cd[start])+1,&cd[start]);	//+1������Ͽ��ַ��ĳ���					//������ӹ����ռ����շ���������� 
	}
	free(cd); //�ͷ���ʱ�ռ� 
}


int main() {
	HuffmanTree HT;					//�Զ���ṹ��  ht
	HuffmanCode HC;
	int w[MAX_NUM], n;
	int i;
	printf("������ĸ���:\n");
	scanf_s("%d", &n);
	printf("����ÿ������Ȩֵ:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	HuffmanCoding(HT, HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("%d�ĺշ�������Ϊ��%s\n", HT[i].weight, HC[i]);
	}
	return 0;
}