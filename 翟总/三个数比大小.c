#include<stdio.h>
int main()
 {int a,b,c,max;
 scanf("%d %d %d",&a,&b,&c);
 if(a>b){max=a;}
 else{max=b;} 
 if(c>max){printf("大的是%d",c);}
 else{printf("大的是%d",max);}
 return 0; 
 
 }
