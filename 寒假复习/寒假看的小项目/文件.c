//�ļ�����ʽ��������
//printf��%��d֮����Բ���4���ַ�
/*#include<stdio.h>
void main(){
	char* num;
	/*printf("%9d\n",123);				//Ĭ���Ҷ���
	printf("%-9d\n",123);				//-��ʾ����� 
	printf("%09d\n",123);				//���+��ʾǿ�����+�� 
	printf("%9.2f\n",123.00);			//����ռ9λС�����ռ2λ 
	printf("%d%n\n",12345,&num);
	printf("%d",num);
}  */ 

//scanfprintf�ķ��ؽ�� 
void main(){
	char a[10]="0";
	scanf("%8s",a);
	printf("%s",*a);
}
