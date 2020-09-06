#include<stdio.h>
int main()
{
	int n,x=0;
	scanf("%d",&n);
	x++;
	n=n/10;
	while(n>0){
		x++;
		n=n/10;
	}
printf("x=%d",x);

 	return 0;
 } 
