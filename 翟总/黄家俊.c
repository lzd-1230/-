#include<stdio.h>
int main(){
	int a[100],n;
	n=10;
	int *p;
	int i;
	for(p=a;p<a+n;p++){
		scanf("%d",p);
	}p--;                                       //��a10��p++�� 
	int b[100];
	for(i=0;i<n;i++,p--){
		b[i]=*p;
		printf("%d",b[i]);
	}return 0;
}                                              //������ �¾������ڵ�ֵ�Ѿ������˱仯 
												//����һ���µ����鴢����p--�������仯�� 

 
