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
	printf("Բ�ܳ�=%f",C);
	printf("Բ���=%f",S);
	printf("������=%f",S1);
	printf("������=%f",V);
	printf("Բ�����=%f",V1);
	return 0;
}
