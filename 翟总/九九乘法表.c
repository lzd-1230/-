#include<stdio.h>
int main()
/*{int a=1,b=1;
while(b<=9){
	a=b;
	printf("\n"); 
	while(a<=9){
		printf("%d*%d=%d",b,a,a*b);
		printf("  "); 
		a++;
	} 
	b++; 
}return 0;
}*/
{int i=1,j,n;
scanf("%d",&n);
while(i<=n){
	j=1;
	while(j<=i){
		printf("%d*%d=%d",j,i,i*j);
		if(i*j<10){
			printf("   ");
		}else{
			printf("  ");
		}
		j++;
	}printf("\n") ;
	i++;
	
	
	}
	return 0;
}

