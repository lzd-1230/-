
#include<stdio.h>
int main()
{int bill,price;
printf("请输入票面和金额\n");
scanf("%d %d",&bill,&price);
if(bill>=price)
{
	printf("找您%d元",bill-price);
}else
{
printf("钱不够");} 
return 0;
 } 
