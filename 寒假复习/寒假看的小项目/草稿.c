#include<stdio.h>
#include<math.h>
//	int i;
//	scanf("%d",&i);
//	printf("i=%d",i);
//	char ch;
//	while((ch=getchar())!='\n')
//		continue;
//	int j;
//	scanf("%d",&j);
//	printf("j=%d",j);
//	return 0;


//�Ƿ�Ϊ���� 
//	int i=8;
//	printf("%f",floor(sqrt(i)+0.5));
//	return 0;

//�Ƿ�Ϊ��ȫƽ��
//int x,n,m;
//scanf("%d",&n);
//x=(int)sqrt(n);
//m=x*x;
//if(m==n)	printf("����ȫƽ����");
//else	printf("������ȫƽ����");
//}

//1+2+3+...+100
//int sum,i;
//sum=0;
//for(i=1;i<=100;i++){
//	sum+=i;
//} 
//printf("sum=%d",sum);
//}


//��1-1001֮�������ܱ�3����������
//int i;
//for(i=1;i<=100;i++){
//	if(i%3==0)	printf("%d\n",i);
//} 
//}

//1+1/2+...+1/100
//int i;
//float sum;
//for(i=1;i<=100;i++){
//		sum=sum+1/(float)(i);
//} printf("sum=%f",sum);
//}

//�ж�һ���������ǲ���0
//float x=0;
//if(fabs(x-10e-6)<10e-6){
//	printf("��0"); 
//}
//else{
//	printf("����0"); 
//}
//}

//1-100�������ͣ�������ƽ��ֵ 
//int cnt,i,sum=0;
//for (i=1;i<101;i++)
//{
//	if (i%2==1){
//		sum+=i;
//		cnt++;
//	}	
//} 
//printf("sum=%d\n",sum);
//printf("��������%d\n",cnt);
//printf("�͵�ƽ��ֵ=%f",1.0*sum/cnt); 

//forѭ����Ƕ�׵���
//int i,j;
//for(i=0;i<5;i++){
//	for(j=2;j<6;j++){
//		printf("hhh\n"); 
//	}
//} 
//}

//�ж�����������ǲ��ǻ�����
//	int a,c,sum=0;
//	scanf("%d",&a);
//	c=a;
//	while(c){
//		sum=sum*10+c%10;
//		c/=10;
//	}
//	if(sum==a)	printf("yes");
//	else 	printf("no");
//}

//쳲��������� 1 2 3 5 8  13 21
//	int i,n,f1=1,f2=2,f3;
//	printf("���ڶ���������\n");
//	scanf("%d",&n);
//	for(i=3;i<=n;i++){
//		f3=f1+f2;
//		f1=f2;
//		f2=f3;
//	}
//	printf("%d",f3);
//}
//	
//һԪ���η��̼����˻�����
//	double x1,x2,a,b,c,delta;
//	int m;
//	char ch;
//	do{
//		printf("������abc��ֵ/n");
//		scanf("%lf %lf %lf",&a,&b,&c);
//		delta=b*b-4*a*c;
//	
//	if(delta>0){
//		x1=(-b+sqrt(delta))/2*a;        	//2aҪд��2*a 
//		x2=(-b-sqrt(delta))/2*a;
//		printf("x1=%f\tx2=%f",x1,x2);
//	}
//	else if(delta<1e-8&&delta>0){
//		printf("x1=x2=%f",x1);
//	}
//	else if(delta<0){
//		printf("ʵ��:%f\t�鲿:%f",-b/2*a,sqrt(delta)/2*a);
//	}
//	
//	printf("�Ƿ���������루Y/N��");
//	scanf(" %c",&ch);
//	if(ch=='Y'||ch=='y'){						//�ַ�����Ҫ��'' 
//		m=1;
//	}
//	else m=0; 	
//	} while(m);
//}

//switchʾ��
//char val;
//	scanf("%c",&val); 
//	switch(val)
//	{
//		case 'a':
//			printf("����");
//			break;
//		case 'b':
//			printf("��");
//			break;
//		case 'c':
//			printf("��");
//			break; 
//	} 
//}

//��ά�������� 
//	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
//	int i,j;
//			for(i=0;i<3;i++){
//				 
//				for(j=0;j<4;j++){
//					printf("%d",a[i][j]);
//				}
//				printf("\n");
//			}
//}
//���1-100�������
//	int i,j,val,t=1;
//	scanf("%d",&val);
//	for(i=2;i<=val;i++){
//		for(j=2,t=1;j<i;j++){
//			if(0==i%j)	t=0;
//		}
//		if(1==t)	printf("%d\t",i);	
//	} 
//}

//��̬�������ܿ纯��ʹ��
//void f(int **q){
////	int i=5;	//��̬ 
//	*q=(int *)malloc(sizeof(int));		//��̬ 
//	**q=5;
//} 
//int *p;
//f(&p);
//printf("%d\n",*p);
//printf("%d\n",*p);
//free(p);
//}

//ͨ��������ɶԽṹ�����������
//	struct date{
//	int year;
//	int month;
//	int day;
//	};
//	void input(struct date*);
//	void output(const struct date*);
//	int main(){
//		struct date a;
//		input(&a);
//		output(&a);
//		return 0;
//	}
//	
//  	void input(struct date *p){
//  		printf("������������\n"); 
//  		scanf("%d%d%d",&(p->year),&(p->month),&(p->day));
//	  }
//	void output(const struct date * p ){
//		printf("%d��%d��%d��",p->year,p->month,p->day);
//		
//	}


//ð������
//	void sort(int *p,int len){
//		int j,i,t;
//		for(j=0;j<len-1;j++)
//		{
//			for(i=0;i<len-j-1;i++)
//			{
//				if(p[i]<p[i+1])
//				{
//					t=p[i];
//					p[i]=p[i+1];
//					p[i+1]=t;	
//				}
//			}
//		}
//	} 
//	int i;
//	int a[7]={5,5,8,10};
//	sort(a,7);
//	for(i=0;i<7;i++){
//		printf("%d\n",a[i]);
//	}
//}

//2.25��ϰmalloc 
//int* create(int );
//void scan(int ,int*);
//void print(int ,int *);
//	int n,i;
//	int *p;
//	printf("�����������С��");
//	scanf("%d",&n);
//	p=create(n);
//	scan(n,p);
//	print(n,p);
//	free(p);
//}
//	int* create(int n){
//		int *p=(int*)malloc(n*sizeof(int));	
//		return p;
//	}
//	void scan(int n,int *p){
//		int i;
//		for(i=0;i<n;i++){
//			scanf("%d",p+i);
//		}
//	}
//	void print(int n,int*p){
//		int i;
//		for(i=0;i<n;i++){
//			printf("%5d",*(p+i));
//		}
//	}
	
//2.26  ����ϵͳ����ܸ����ٿռ�
//int main(){
//	int *p,t=0;
//	while((p=malloc(100*1024*1024))){
//		t++;
//	}
//	printf("һ��������%d00M���ڴ�",t);
//	free(p);
//	return 0;
//} 
//	 

//2.28 �ṹ��ָ�븴ϰ
typedef struct {
	int year;
	int month;
	int day;
}d; 
struct d* get(){
	d a;
	d* p=&a;
	scanf("%d%d%d",&a.year,&a.month,&a.day);
	return p;
}
int main(){
	d *p=get();
	printf("%d.%d.%d",p->year,p->month,p->day);
	return 0;
}
