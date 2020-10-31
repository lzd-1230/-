#include<stdio.h>

int Recursion(int n);

int main()
{
	int n;
	printf("input:");
	scanf("%d",&n);
	
	printf("%d! = %d\n",n,Recursion(n));
}

int Recursion(int n)
{
	if(n == 0 || n == 1)
		return 1;
	if(n>1)
		return n*Recursion(n-1);
}
