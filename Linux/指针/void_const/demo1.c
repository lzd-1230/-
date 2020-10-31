#include<stdio.h>

int main()
{
	int m = 10;
	double n = 3.14;

	void* p;
	void* q;

	p = (void *)&m;
	q = (void *)&n;

	printf("%d %f\n",*(int*)p,*(double*)q);
}
