#include<stdio.h>
/*
int main()
{
	int a =10;
	int *p =&a;
	
	double b =10.0;
	double *q = &b;
	
	printf("%p,%p\n",p,p+2);	
	printf("%p,%p\n",q,q+2);
	
	return 0;
}*/

int main()
{
	int a[3][2]= {{1,2},{3,4},{5,6}};
	int *p, *q, n;

	//p = a;                //指针类型不匹配！
	//a[0]++;		//会报错，数组名是常量不能++
	p = a[0];		//a[0]是一个一维数组名
	

	//检验指针类型
	printf("%p\t%p\n",p,p+1);	
	printf("%p\t%p\n",a,a+1);

	n = sizeof(a)/sizeof(int);

	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d ",*(p+i));
	puts("");
	return 0;
}

