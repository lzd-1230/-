#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main() {
	float xn,x,a,b;
	scanf("%f %f",&xn,&a);
	b=sqrt(a);
	for(x=xn;abs(xn-b)>0.00001;x=xn){
		xn=(x+a/x)/2;
	}
	printf("%f %f",xn,x);
return 0;
}


