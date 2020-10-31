#include<stdio.h>

int Recursion(int n);

int main()
{
	int n = 11;
	for(int i=0;i<n;i++)
	{
		printf("f(%d) = %d\n",i,Recursion(i));

	}
}

int Recursion(int n)
{
	if(n == 1 || n == 2)
		return 1;
	if(n>2)
		return Recursion(n-1)+Recursion(n-2);
}
