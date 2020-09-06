#include<stdio.h>
//将3x3数组转置 ①将a【0】地址作为实参在执行过程中实现行列互换
//②调用结束后输出转置数组
//行列指针代表什么含义？怎样表示？怎样表示i行j列的元素及其地址 
int main()
{   void swap(int *q,int b[3][3]);                    //声明函数 
	int a[3][3];
	int i,j;
	int *p;p=a;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",a[i]+j);
		}
	}
	     swap(p,a);                     //调用转置函数 
	     p=&a[0][0];
	     printf("转置后的数组\n");
	for(i=0;i<3;i++){                 //输出转置后的函数 
		for(j=0;j<3;j++){
			printf("%d",*(p+j));
			if (j==2) printf("\n");
			}p++;
		}
		return 0;}
		void swap(int *q,int k[3][3]){           //定义函数 
			int a,b;
			q=&k[0][0];
			for(a=0;a<3;a++,q++){
				for(b=0;b<3;b++){
					*(q+b)=*((q+b)+a);
				}
			}
		}   
		
		//逆序 
		
	 
	

