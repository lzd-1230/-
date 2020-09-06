#include<stdio.h>
#define pi 3.141592
int main()
{
	float h;
	float C,S,S1,V,V1;
	float r;	
	scanf("%f %f",&h,&r);
	C=2*pi*r;
	S=pi*r*r;
	S1=4*pi*r*r;
	V=4/3*pi*r*r;
	V1=pi*r*r*h;
	printf("圆周长=%f",C);
	printf("圆面积=%f",S);
	printf("球表面积=%f",S1);
	printf("球的体积=%f",V);
	printf("圆柱体积=%f",V1);
	return 0;
}
