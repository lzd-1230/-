#include<stdio.h>
#include<string.h> 
/*�±� 
ΪʲôҪ�ṹ�壿
	�洢���ɸ�ӵ�ж����Եı���(������������) 
	
�ṹ��ͽṹ�����������
	�ṹ����һ������like int
	~������һ������like  a 
��ֵ�ͳ�ʼ��
	��ʼ��ʱ���帳ֵ
	֮��ֻ�ܶԳ�Ա������ֵ 
	 
���ȡ����Ա
	1.�ṹ�������.��Ա��
	2.ָ�������->��Ա��	���ڲ���ʵ��(*ָ�������).��Ա�� 

�ṹ�����������
	�ṹ��������ܼӼ��˳�
	ֻ���໥��ֵ 
	
�ṹ�����ָ����Ϊ�������ݵ�����
	����ָ������ں����ж�������޸�
	��ָ���ʡ�ڴ棬��Ϊ�ṹ��һ��Ƚϴ�����ٿ���һ���ṹ���β����ܴ� 
	��ϣ���ں����н����޸�����const
	 
��̬������ѧ����Ϣ�Ľṹ������
	�û�������һ������Ȼ�� 
	
���� 

*/










//���� 
//����:��������ݿ���һ������
//struct date{         				//�����ṹ���� ����ģ�������������(�ֺŲ�����) 
//	int day;
//	int month;						//�����Ա���� 
//	int year; 
//}a;									//����ṹ����a��ʵ�� 
////��ʼ������ 
//int main(){
// 		a.day=27;
//		a.month=1;
//		a.year=2020;				//����ṹ���� 
//
////��	struct date today={27,1,2020};
//	printf("%d-%d-%d",a.year,a.month,a.day);
//	return 0;
//}
//�ṹ�������ͶƱ����(�е�����) 
//struct vote {
//	char name[20];
//	int num;
//}candidate[3]={"li",0,"zhang",0,"wang",0};
//int main(){
//	int i,j;
//	char choice[20];
//	for(i=0;i<2;i++)
//	{
//		scanf("%s",choice);
//		for(j=0;j<3;j++)
//		{
//			if(strcmp(choice,candidate[j].name)==0)
//			{
//				candidate[j].num++;
//			}
//		}
//	}
//	printf("Result:\n");
//	for(j=0;j<=2;j++){
//		printf("%s:%d\n",candidate[j].name,candidate[j].num);
//	}
//	return 0;
//} 
// 
	 

//�ṹ����Ϊ��������
/*struct p{
	int x;
	int y;
}; 
struct p getstru(){
	struct p p1;
	scanf("%d",&p1.x);
	scanf("%d",&p1.y);
	return p1;
}

int main(){
	struct p y={0,0};
	y=getstru();
	printf("x=%d\ny=%d",y.x,y.y);
	return 0;
}*/
//�ṹ��ָ�� 
/*
struct p{
	int x;
	int y;
}; 
struct p* get(struct p *a){
	scanf("%d",&a->x);
	scanf("%d",&a->y);
	return a;
}
int  main(){
	struct p a={0,0};
	get(&a);
	printf("x=%i\ny=%i",get(&a)->x,get(&a)->y);
	return 0;
} */

//�ṹ����ͽṹǶ��
/*struct time {
	int sec;
	int hou;
}; 

void main(){
	struct time a[2]={
	{10,10},{11,11}		
	};
	int i;
	for(i=0;i<2;i++){
		printf("%dʱ %d��\n",a[i].hou,a[i].sec);
	}
}*/
//�ṹ��ָ��ָ������ 
//struct student{
//	char name[20];
//	int score;
//	}stu[3]={"li",90,"wang",80,"zhang",70};
//int main()
//{
//	struct student *p;
//	for(p=stu;p<stu+3;p++){
//		printf("%s:%d\n",p->name,p->score);
//	}
//return 0;			
//} 
//typedef���÷�

//typedef struct{
//	int day;
//	int month;
//	int year;
//}d;        						//ֻ�����һ�����ʲ������ǹ��ĵ� 
//void main(){
//d a={9,9,2019};
//printf("%d-%d-%d",a.day,a.month,a.year);
//} 

//ȫ�ֱ���
//�ٲ���ʼ���ᱻĬ�ϸ�ֵΪ0
//���ں�����������ͬ��������ᱻ����(��С��Χ�ı�����Ѵ�Χ�ĸ�����) 
//�۳�ʼ����ʱ�� 

//��̬���ر���(ֻ�ᱻ��ʼ��һ��) 
//ʵ�����������ȫ�ֱ�������Ϊ��ȫ�ֵ������ڣ���������Ҳֻ���ڱ��� 
/*f(){
	static int a=1;   
	a+=2;
	printf("a=%d\n",a);
}
void main(){
	f();
	f();
	f();
}*/

//����ָ��ĺ��� 
//�����ر��ر����ĵ�ַʱ��Σ�գ���Ϊ�뿪�˺�����û�˱�֤ a��ֵ���������� 
/*int *f(){
	static int a=2;
	return &a;
}
void main(){
	int *p=f();
	printf("%p\n",p);
	printf("%d",*p);
}*/

//����Ԥ����ָ��#   		��.c���ļ�Ԥ����Ϊ.i 
//��#define ���� �ı�
//��ȫ���ı��滻 
//c��Ԥ�ȶ���õĺ�:_LINE_ _FILE_ _DATE_ _TIME_ _STDC_

//�����ĺ�
/*
#define s(x) ((x)*3.14) 			//Ҫ�㣺����ֵҪ�����ţ�ÿ���������ֵĵط���Ҫ��() 
void main(){
	printf("%f",s(5));
}*/

//����ṹ�����Դ�ļ���.c����ҪŪ��һ����Ŀ��ȥ���γ�.o�ļ����ٴ����� 
//ͷ�ļ��������˺���ԭ��eg:int max(int a,int b)
//ʵ�ʾ��ǽ�.h�ļ��е�����ԭ�ⲻ���ز������ 
//���溯�������� (ͷ�ļ���ֻ�ܷ�����) 
//.h�ļ���ֻ���к�����ģ�ͣ�ֻ��Ϊ�˱�֤��Ĳ�����������ȷ��
//��׼����ĺ���Դ������Զ�����ĳ������ӣ����Ծ�����û����ͷ�ļ�Ҳһ��������
//ֻ�����Ǳ�����ȥ����Ĳ�������


//�����⹫���ĺ���(ֻϣ�����.c�ļ��ò�ϣ�������)+static
//��ȫ�ֱ�����+static->���ֻ���ڸ�.c�ļ���ʹ�õ�

//�����Ͷ���
//��������������(���ܸ�ֵ)
//����ٺ�����ȫ�ֱ��� 

//Ϊ�˷�ֹ�ظ�������ͷ�ļ����ñ�׼ͷ�ļ���ʽ
/*#ifndef_�ļ���_H_
#define_�ļ���_H_

#endif*/ 


 


 
