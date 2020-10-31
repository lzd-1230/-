#include<stdio.h>

int main()
{
	int a[] = {1,2};
	int* p[2] = {&a[0],&a[1]};

	int** q1;
	q1 = &p[0];

	printf("%d %d %d\n",**q1,*p[1],**(q1+1));
	return 0;	
}
