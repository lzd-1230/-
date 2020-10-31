#include<stdio.h>

int Add(int a,int b)
{
	return a+b;
}
int main()
{
	int (*p) (int,int);
	p = Add;
	printf("%d\n",(*p)(1,2));
}
