#include<stdio.h>

int main()
{
	int n = 10;
	int* p = &n;
	
	int * *q = &p;
	printf("%d\n",**q);

	return 0;	
}
