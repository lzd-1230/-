#include<stdio.h>

int main()
{
	int* p[3];	//数据类型：int* 	有三个int*
	int a[] = {1,2,3};

	//有组织的几个指针
	p[0] = a;
	p[1] = a + 1;
	p[2] = a + 2;

	printf("%d,%d,%d\n",*(p[0]),*(p[1]),*(p[2]));
}
