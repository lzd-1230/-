#include<stdio.h>
int main(){
	int a[100],n;
	n=10;
	int *p;
	int i;
	for(p=a;p<a+n;p++){
		scanf("%d",p);
	}p--;                                       //到a10后p++了 
	int b[100];
	for(i=0;i<n;i++,p--){
		b[i]=*p;
		printf("%d",b[i]);
	}return 0;
}                                              //错了在 新旧数组内的值已经发生了变化 
												//定义一个新的数组储存则p--不发生变化了 

 
