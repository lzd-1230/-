#include<stdio.h>
int main(){
	int x,n,t=0,sum=0,a,b,r=1;
	scanf("%d %d",&a,&b);
	for(x=a;x<=b;x++){
		r=1;                              //确保每一个数开始时r都是1 
		for(n=2;n<x-1;n++){
			if(x%n==0){
				r=0;
				break;
			}
		}if(r){
			sum+=x;
			t++;
		}			
	}printf("素数和=%d	素数个数=%d",sum,t);
	return 0;	
}

