#include<stdio.h>

int main()
{
	int a[2][3] = {{1,2,3},{4,5,7}};
	int* p[2] = {a[0],a[1]};

	printf("%d %d \n",p[0][1],*(p[1]-2));
	printf("%d %d\n",p[1][2],*(p[1]+2));
}
