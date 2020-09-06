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


//是否为整数 
//	int i=8;
//	printf("%f",floor(sqrt(i)+0.5));
//	return 0;

//是否为完全平方
//int x,n,m;
//scanf("%d",&n);
//x=(int)sqrt(n);
//m=x*x;
//if(m==n)	printf("是完全平方数");
//else	printf("不是完全平方数");
//}

//1+2+3+...+100
//int sum,i;
//sum=0;
//for(i=1;i<=100;i++){
//	sum+=i;
//} 
//printf("sum=%d",sum);
//}


//求1-1001之间所有能被3整除的数字
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

//判断一个浮点数是不是0
//float x=0;
//if(fabs(x-10e-6)<10e-6){
//	printf("是0"); 
//}
//else{
//	printf("不是0"); 
//}
//}

//1-100的奇数和，个数，平均值 
//int cnt,i,sum=0;
//for (i=1;i<101;i++)
//{
//	if (i%2==1){
//		sum+=i;
//		cnt++;
//	}	
//} 
//printf("sum=%d\n",sum);
//printf("奇数个数%d\n",cnt);
//printf("和的平均值=%f",1.0*sum/cnt); 

//for循环的嵌套调试
//int i,j;
//for(i=0;i<5;i++){
//	for(j=2;j<6;j++){
//		printf("hhh\n"); 
//	}
//} 
//}

//判断所输入的数是不是回文数
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

//斐波那契数列 1 2 3 5 8  13 21
//	int i,n,f1=1,f2=2,f3;
//	printf("大于二的序列数\n");
//	scanf("%d",&n);
//	for(i=3;i<=n;i++){
//		f3=f1+f2;
//		f1=f2;
//		f2=f3;
//	}
//	printf("%d",f3);
//}
//	
//一元二次方程加上人机交互
//	double x1,x2,a,b,c,delta;
//	int m;
//	char ch;
//	do{
//		printf("请输入abc的值/n");
//		scanf("%lf %lf %lf",&a,&b,&c);
//		delta=b*b-4*a*c;
//	
//	if(delta>0){
//		x1=(-b+sqrt(delta))/2*a;        	//2a要写成2*a 
//		x2=(-b-sqrt(delta))/2*a;
//		printf("x1=%f\tx2=%f",x1,x2);
//	}
//	else if(delta<1e-8&&delta>0){
//		printf("x1=x2=%f",x1);
//	}
//	else if(delta<0){
//		printf("实部:%f\t虚部:%f",-b/2*a,sqrt(delta)/2*a);
//	}
//	
//	printf("是否继续请输入（Y/N）");
//	scanf(" %c",&ch);
//	if(ch=='Y'||ch=='y'){						//字符常量要加'' 
//		m=1;
//	}
//	else m=0; 	
//	} while(m);
//}

//switch示例
//char val;
//	scanf("%c",&val); 
//	switch(val)
//	{
//		case 'a':
//			printf("优秀");
//			break;
//		case 'b':
//			printf("良");
//			break;
//		case 'c':
//			printf("差");
//			break; 
//	} 
//}

//二维数组的输出 
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
//输出1-100间的素数
//	int i,j,val,t=1;
//	scanf("%d",&val);
//	for(i=2;i<=val;i++){
//		for(j=2,t=1;j<i;j++){
//			if(0==i%j)	t=0;
//		}
//		if(1==t)	printf("%d\t",i);	
//	} 
//}

//静态变量不能跨函数使用
//void f(int **q){
////	int i=5;	//静态 
//	*q=(int *)malloc(sizeof(int));		//动态 
//	**q=5;
//} 
//int *p;
//f(&p);
//printf("%d\n",*p);
//printf("%d\n",*p);
//free(p);
//}

//通过函数完成对结构体的输入和输出
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
//  		printf("请输入年月日\n"); 
//  		scanf("%d%d%d",&(p->year),&(p->month),&(p->day));
//	  }
//	void output(const struct date * p ){
//		printf("%d年%d月%d日",p->year,p->month,p->day);
//		
//	}


//冒泡排序
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

//2.25复习malloc 
//int* create(int );
//void scan(int ,int*);
//void print(int ,int *);
//	int n,i;
//	int *p;
//	printf("请输入数组大小：");
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
	
//2.26  测试系统最大能给多少空间
//int main(){
//	int *p,t=0;
//	while((p=malloc(100*1024*1024))){
//		t++;
//	}
//	printf("一共申请了%d00M的内存",t);
//	free(p);
//	return 0;
//} 
//	 

//2.28 结构体指针复习
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
