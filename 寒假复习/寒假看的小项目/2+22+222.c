#include<stdio.h>
int main(){
	int sum,a,n,i,t=0;
	scanf("%d %d",&a,&n);
	for(i=1;i<=n;i++){								//2 2*10+2 (2*10+2)*10+a
	t=t*10+a;	
	sum+=t;
	}printf("%d",sum);
} 
