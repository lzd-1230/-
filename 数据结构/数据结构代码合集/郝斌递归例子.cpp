#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//�׳˵ĵݹ�ʵ��
/* 
long f(int );
int main()
{
	printf("%ld",f()) ;
	return 0;
} 
/*��val!ֻ��Ҫ��(val-1)!��*val 
 	��ģΪn������Ľ�������ֹ�ģn-1������Ľ�������!!! 
	��ģ�ڲ�ͣ�ĵݼ� 
long f(int val)
{
	if(val==1)
		return 1;
	else
		return f(val-1)*val;	//an=a(n-1)*n	������˾����ұߵ���ʽ 
}

*/ 
/* 
//1+2+3+4...+100�ĵݹ�ʵ��
long sum(int );
int main()
{
	printf("%d",sum(100));
	return 0;
}
long sum(int n)
{
	if(n==1)	return 1;
	else	return sum(n-1)+n;
}
*/
//����������:�Լ������Լ�������һ����ֹ����,��Ȼ�����ݹ� 
/* 
int f(int n)
{
	if(n<3)
		printf("����\n");		//ֻҪ�����һ�κ�Ͳ��ٵݹ��� 
	else
		n=f(n-1);				//n��ֵÿһ�ε��þͼ�С					
	return n;
} 
int main()
{
	int val;
	val=f(5);
	printf("%d",val);
	return 0;
}
*/ 

//��ŵ��
void hannuota(int ,char ,char,char);
int main()
{
	char ch1='a';
	char ch2='b';
	char ch3='c';
	int n;
	printf("������Ҫ�ƶ����ӵĸ���:");
	scanf("%d",&n);
	hannuota(n,'a','b','c'); 
	return 0; 
} 
void hannuota(int n,char a,char b,char c)//λ��1������������Ӵ��Ƶ�����,λ��2��������,λ��3����Ŀ���� 
{
	/*
	�����1������
		ֱ�ӽ�A�����ϵ��Ƶ�C����
	�������������1
		�Ƚ�A��n-1������C�Ƶ�B������(��ʱA�Ͻ�ʣһ��������һ)
		ֱ�ӽ�A�����ϵ��Ƶ�C(��ʱC�ϵ��������Ǹ�����,��˵�Ч�ڿ�����,��������) 
		B�ϵ�n-2�����ӽ���C�Ƶ�A,Ȼ��A�ֺܶ���,�ݹ�����Լ� 
	*/		 
	
	if(n==1)
	{
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n",n,a,c);
	}
	else
	{
		hannuota(n-1,a,c,b);			//��n-1�����C�ŵ�B 
		printf("�����Ϊ%d�����Ӵ�%c�����Ƶ�%c����\n",n,a,c);	//ֱ�Ӱ�a��ʣ���Ǹ���c��ɹ�ģ�ļ�С 
		hannuota(n-1,b,a,c);			//�ٿ��ǰ�b����n-1�����ӽ���A�Ƶ�C
	} 
}
 
