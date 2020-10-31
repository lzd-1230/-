#include<stdio.h>

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);

	void* p = a;

	for(int i=0;i<n;i++)
		//printf("%d",a[i]);
		printf("%d",*((int*)p+i));
	puts("");
}
