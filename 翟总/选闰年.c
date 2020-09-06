#include<stdio.h>
int main()
{int year;
year=1900;
for(year=1900;year<2000;year++)
{	if(year%4==0)
	if(year%100==0){
	if(year%400==0){
	printf("%d",year);
	}else{
	return year;
	}
	}else{
	printf("%d",year);
	}
	else{
	return year;
	}
	
	
}
		
	return 0;}
	
	

