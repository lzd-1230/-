#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
int main()
{	
	int x,a,b,c;
	for(x=1;x<=999;x++){
		a=x%10;     //��λ�� 
		b=x/100;	//��λ�� 
		c=x/10%10;	//ʮλ�� 
		if(pow(a,3)+pow(b,3)+pow(c,3)==x){
			printf("%3d ",x);
		}
		}
return 0;}
