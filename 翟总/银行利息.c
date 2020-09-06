#include<stdio.h>
int main()
{double c;
int b;
printf("输入本金  ");
scanf("%d",&b);
c=b*(1+0.03)*(1+0.03)*(1+0.03);
printf("您的转存金额%f",c);
return 0;
}
