#include<stdio.h>
/*
设n个小朋友过河
T[i]为第i个小朋友过河时间
总时间为f
*/
#define N 5+1
int T[] = {-999,1,3,6,12,8};		//数组的第0位不用
void Sort(int* p, int len);
void Print_Array(int* p, int len);
int Cross(int* p, int len);

int main()
{
	Sort(T, N);
	
	int fn = Cross(T, N);

	printf("过桥的最短时间为%d\n",fn);
}

//计算n个人过桥的总时间
int Cross(int* p, int len)
{
	int fn = 0;

	if (N <= 2)
		return T[N];

	if (N == 3)
		return T[1] + T[2] + T[3];

	//N>=4时
	int fn_2 = T[2];				//f(n-2)的起始
	int fn_1 = T[1] + T[2] + T[3];	//f(n-1)的起始
	//迭代
	for (int i = 4; i < N; i++)
	{
		fn = T[1] + 2 * T[2] + T[i] + fn_2;
		//fn-2更新
		fn_2 = fn_1;
		//fn-1更新
		fn_1 = fn;
	}
	return fn;
}

//打印数组
void Print_Array(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
}

//冒泡排序
void Sort(int* p, int len)
{
	int tmp;
	for (int i = 1; i < N; i++)
	{
		for (int j = len - 2; j >= i; j--)
		{
			if (p[j] > p[j + 1])
			{
				tmp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = tmp;
			}
		}
	}
}