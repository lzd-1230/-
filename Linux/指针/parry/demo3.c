#include<stdio.h>

int main()
{
	int a[2][3] = {{1,2,3},{4,5,7}};
	int* p[2] = {a[0],a[1]};
	int* q =&a[1][2];
	int m =2,n=3,sum = 0;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			printf("%d\n",p[i][j]);
			sum += p[i][j];
		}

	printf("sum = %d\n",sum);
	printf("size of(p) = %ld\n",sizeof(p));
	printf("size of(a) = %ld\n",sizeof(a));
	printf("size of(q) = %ld\n",sizeof(q));
	
}
