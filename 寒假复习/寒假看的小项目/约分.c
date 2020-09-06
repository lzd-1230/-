#include <stdio.h>
int main(){
	int a,b,z,t;
	scanf("%d/%d",&a,&b);
	int d1,d2;
	d1=a;	d2=b;
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}z=a;
	printf("约分结果%d/%d",d1/z,d2/z); 
  return 0;
  }

