#include<stdio.h>

double Power(double x,int n);

int main()
{
	double x;
	int n;
	printf("input:");
	scanf("%lf %d",&x,&n);

	double r = Power(x,n);
	printf("x^n=%lf\n",r);
}

double Power(double x,int n)
{
	double r = 1;
	for(int i=0;i<n;i++)
	{
		 r *= x;
	}	
	return r;
}
