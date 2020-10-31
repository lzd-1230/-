#include<stdio.h>
#include<stdlib.h>

int Compare(const void* ,const void*);

int main()
{
	int a[] = {22,45,4,4,3,2,45,5,2};
	int n = sizeof(a)/sizeof(int);
	qsort(a,n,sizeof(int),Compare);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

int Compare(const void* p,const void* q)
{
	return (*(int*)p - *(int*)q);	
}
