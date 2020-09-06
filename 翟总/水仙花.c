#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
int main()
{	
	int x,a,b,c;
	for(x=1;x<=999;x++){
		a=x%10;     //个位数 
		b=x/100;	//百位数 
		c=x/10%10;	//十位数 
		if(pow(a,3)+pow(b,3)+pow(c,3)==x){
			printf("%3d ",x);
		}
		}
return 0;}
