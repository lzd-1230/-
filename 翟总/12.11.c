#include<stdio.h>
//��3x3����ת�� �ٽ�a��0����ַ��Ϊʵ����ִ�й�����ʵ�����л���
//�ڵ��ý��������ת������
//����ָ�����ʲô���壿������ʾ��������ʾi��j�е�Ԫ�ؼ����ַ 
int main()
{   void swap(int *q,int b[3][3]);                    //�������� 
	int a[3][3];
	int i,j;
	int *p;p=a;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",a[i]+j);
		}
	}
	     swap(p,a);                     //����ת�ú��� 
	     p=&a[0][0];
	     printf("ת�ú������\n");
	for(i=0;i<3;i++){                 //���ת�ú�ĺ��� 
		for(j=0;j<3;j++){
			printf("%d",*(p+j));
			if (j==2) printf("\n");
			}p++;
		}
		return 0;}
		void swap(int *q,int k[3][3]){           //���庯�� 
			int a,b;
			q=&k[0][0];
			for(a=0;a<3;a++,q++){
				for(b=0;b<3;b++){
					*(q+b)=*((q+b)+a);
				}
			}
		}   
		
		//���� 
		
	 
	

