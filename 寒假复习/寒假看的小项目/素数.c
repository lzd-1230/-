#include<stdio.h>
int main(){
	int x,n,t=0,sum=0,a,b,r=1;
	scanf("%d %d",&a,&b);
	for(x=a;x<=b;x++){
		r=1;                              //ȷ��ÿһ������ʼʱr����1 
		for(n=2;n<x-1;n++){
			if(x%n==0){
				r=0;
				break;
			}
		}if(r){
			sum+=x;
			t++;
		}			
	}printf("������=%d	��������=%d",sum,t);
	return 0;	
}

